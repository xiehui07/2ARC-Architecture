#include "stdlib.h"
#include "mylib.c"
#include "start_map.h"
#include "start_col.h"
#include "gaming_map.h"
#include "gaming_col.h"
#include "win_map.h"
#include "win_col.h"
#include "fail_map.h"
#include "fail_col.h"

void display_paddle(u8 x, u8 y) {
    putSP(0, x, y, 0xAC, 2);
    putSP(1, x+8, y, 0xAD, 2);
    putSP(2, x, y+8, 0xBC, 2);
    putSP(3, x+8, y+8, 0xBD, 2);
    putSP(4,x+16,y,0xAC,2);
    putSP(5,x+24,y,0xAD,2);
    putSP(6,x+16,y+8,0xBC,2);
    putSP(7,x+24,y+8,0xBD,2);
    putSP(8,x+32,y,0xAC,2);
    putSP(9,x+40,y,0xAD,2);
    putSP(10,x+32,y+8,0xBC,2);
    putSP(11,x+40,y+8,0xBD,2);
}

int blocks_flag[5];

void main() {
    int x_direction = 1;
    int y_direction = -1;
    int blood = 3;
    int start_map_flag = 1;
    int gaming_map_flag = 0;
    int win_map_flag = 0;
    int fail_map_flag = 0;
    int display_flag = 1;
    int score = 0;
    u8 key = 0;
    u8 paddle_x = 80, paddle_y = 210;
    u8 ball_x = 90, ball_y = 200;
    int i = 0;
    for (i; i < 5; i++) {
        blocks_flag[i] = 1;
    }
    wait_VBlank();
    while (1) {
        while (start_map_flag == 1) {
            if (display_flag == 1) {
                disable_graphics();
                load_full_name_0((u8*)start_map);
                load_BG_palette((u8*)start_col);
                load_SP_palette((u8*)start_col);
                enable_graphics();
            }
            key = read_joy();
            if (presskey(button_START)) {
                gaming_map_flag = 1;
                start_map_flag = 0;
                display_flag = 1;
                disable_graphics();
                load_full_name_0((u8*)gaming_map);
                load_BG_palette((u8*)gaming_col);
                load_SP_palette((u8*)gaming_col);
                enable_graphics();
                wait_VBlank();
            }
            display_flag = 0;
        }

        while (gaming_map_flag == 1) {
            key = read_joy();
            if(presskey(button_RIGHT) && paddle_x<160) {
                paddle_x++;
            }
            if(presskey(button_LEFT) && paddle_x>45) {
                paddle_x--;
            }
            ball_x += x_direction;
            ball_y += y_direction;

            if (ball_y >= 240) {
                blood -= 1;
                ball_x = 90;
                ball_y = 200;
                x_direction = 1;
                y_direction = -1;
            }
            if (blood <= 0) {
                gaming_map_flag = 0;
                fail_map_flag = 1;
                display_flag = 1;
            }
            score = 0;
            for (i=0; i<5; i++) {
                if (blocks_flag[i] == 0) {
                    score += 1000;
                }
            }
			wait_VBlank();
            gotoxy(0, 0);
            cprintf("score=%d       blood=%d   ", score, blood);
            if (score == 5000) {
                gaming_map_flag = 0;
                win_map_flag = 1;
                display_flag = 1;
            }
            if (ball_x <= 45) {
                x_direction *= -1;
            }
            if (ball_x >= 198) {
                x_direction *= -1;
            }
            if (ball_y <= 25) {
                y_direction *= -1;
            }
            if (ball_x <= paddle_x+40 && ball_x >= paddle_x && ball_y == paddle_y-2) {
                y_direction *= -1;
            }
            display_paddle(paddle_x, paddle_y);
            putSP(12,ball_x,ball_y,0xAE,1);
            putSP(13,ball_x+8,ball_y,0xAF,1);
            putSP(14,ball_x,ball_y+8,0xBE,1);
            putSP(15,ball_x+8,ball_y+8,0xBF,1);
			wait_VBlank();

            if(blocks_flag[0] == 1) {
                putSP(12, 48, 46, 0xC2, 0);
                putSP(13, 56, 46, 0xC3, 0);
                putSP(14, 64, 46, 0xC3, 0);
                putSP(15, 72, 46, 0xC4, 0);
                putSP(16, 48, 54, 0xD2, 0);
                putSP(17, 56, 54, 0xD3, 0);
                putSP(18, 64, 54, 0xD3, 0);
                putSP(19, 72, 54, 0xD4, 0);
                if ((ball_x+8==48 || ball_x+8 == 80) && ball_y+8<=62 && ball_y+8>=46) {
                    x_direction *= -1;
                    blocks_flag[0] = 0;
                } else if ((ball_y+8==46 || ball_y+8 == 62) && ball_x+8<=80 && ball_x+8>=48) {
                    y_direction *= -1;
                    blocks_flag[0] = 0;
                }
            } else {
                putSP(12, 48, 46, 0xC2, 32);
                putSP(13, 56, 46, 0xC3, 32);
                putSP(14, 64, 46, 0xC3, 32);
                putSP(15, 72, 46, 0xC4, 32);
                putSP(16, 48, 54, 0xD2, 32);
                putSP(17, 56, 54, 0xD3, 32);
                putSP(18, 64, 54, 0xD3, 32);
                putSP(19, 72, 54, 0xD4, 32);
            }

            if(blocks_flag[1] == 1) {
                putSP(20, 80, 46, 0xC2, 0);
                putSP(21, 88, 46, 0xC3, 0);
                putSP(22, 96, 46, 0xC3, 0);
                putSP(23, 104, 46, 0xC4, 0);
                putSP(24, 80, 54, 0xD2, 0);
                putSP(25, 88, 54, 0xD3, 0);
                putSP(26, 96, 54, 0xD3, 0);
                putSP(27, 104, 54, 0xD4, 0);
                if ((ball_x+8==80 || ball_x+8 == 112) && ball_y+8<=62 && ball_y+8>=46) {
                    x_direction *= -1;
                    blocks_flag[1] = 0;
                } else if ((ball_y+8==46 || ball_y+8 == 62) && ball_x+8<=112 && ball_x+8>=80) {
                    y_direction *= -1;
                    blocks_flag[1] = 0;
                }
            } else {
                putSP(20, 80, 46, 0xC2, 32);
                putSP(21, 88, 46, 0xC3, 32);
                putSP(22, 96, 46, 0xC3, 32);
                putSP(23, 104, 46, 0xC4, 32);
                putSP(24, 80, 54, 0xD2, 32);
                putSP(25, 88, 54, 0xD3, 32);
                putSP(26, 96, 54, 0xD3, 32);
                putSP(27, 104, 54, 0xD4, 32);
            }

            if(blocks_flag[2] == 1) {
                putSP(28, 112, 46, 0xC2, 0);
                putSP(29, 120, 46, 0xC3, 0);
                putSP(30, 128, 46, 0xC3, 0);
                putSP(31, 136, 46, 0xC4, 0);
                putSP(32, 112, 54, 0xD2, 0);
                putSP(33, 120, 54, 0xD3, 0);
                putSP(34, 128, 54, 0xD3, 0);
                putSP(35, 136, 54, 0xD4, 0);
                if ((ball_x+8==112 || ball_x+8 == 144) && ball_y+8<=62 && ball_y+8>=46) {
                    x_direction *= -1;
                    blocks_flag[2] = 0;
                } else if ((ball_y+8==496|| ball_y+8 == 62) && ball_x+8<=144 && ball_x+8>=112) {
                    y_direction *= -1;
                    blocks_flag[2] = 0;
                }
            } else {
                putSP(28, 112, 46, 0xC2, 32);
                putSP(29, 120, 46, 0xC3, 32);
                putSP(30, 128, 46, 0xC3, 32);
                putSP(31, 136, 46, 0xC4, 32);
                putSP(32, 112, 54, 0xD2, 32);
                putSP(33, 120, 54, 0xD3, 32);
                putSP(34, 128, 54, 0xD3, 32);
                putSP(35, 136, 54, 0xD4, 32);
            }

            if(blocks_flag[3] == 1) {
                putSP(36, 144, 46, 0xC2, 0);
                putSP(37, 152, 46, 0xC3, 0);
                putSP(38, 160, 46, 0xC3, 0);
                putSP(39, 168, 46, 0xC4, 0);
                putSP(40, 144, 54, 0xD2, 0);
                putSP(41, 152, 54, 0xD3, 0);
                putSP(42, 160, 54, 0xD3, 0);
                putSP(43, 168, 54, 0xD4, 0);
                if ((ball_x+8==144 || ball_x+8 == 176) && ball_y+8<=62 && ball_y+8>=46) {
                    x_direction *= -1;
                    blocks_flag[3] = 0;
                } else if ((ball_y+8==46 || ball_y+8 == 62) && ball_x+8<=176 && ball_x+8>=144) {
                    y_direction *= -1;
                    blocks_flag[3] = 0;
                }
            } else {
                putSP(36, 144, 46, 0xC2, 32);
                putSP(37, 152, 46, 0xC3, 32);
                putSP(38, 160, 46, 0xC3, 32);
                putSP(39, 168, 46, 0xC4, 32);
                putSP(40, 144, 54, 0xD2, 32);
                putSP(41, 152, 54, 0xD3, 32);
                putSP(42, 160, 54, 0xD3, 32);
                putSP(43, 168, 54, 0xD4, 32);
            }

            if(blocks_flag[4] == 1) {
                putSP(44, 176, 46, 0xC2, 0);
                putSP(45, 184, 46, 0xC3, 0);
                putSP(46, 192, 46, 0xC3, 0);
                putSP(47, 200, 46, 0xC4, 0);
                putSP(48, 176, 54, 0xD2, 0);
                putSP(49, 184, 54, 0xD3, 0);
                putSP(50, 192, 54, 0xD3, 0);
                putSP(51, 200, 54, 0xD4, 0);
                if ((ball_x+8 == 176 || ball_x+8 == 208) && ball_y<=62 && ball_y+16>=46) {
                    x_direction *= -1;
                    blocks_flag[4] = 0;
                } else if ((ball_y+8==46 || ball_y+8 == 62) && ball_x+8<=208 && ball_x+8>=176) {
                    y_direction *= -1;
                    blocks_flag[4] = 0;
                }
            } else {
                putSP(44, 176, 46, 0xC2, 32);
                putSP(45, 184, 46, 0xC3, 32);
                putSP(46, 192, 46, 0xC3, 32);
                putSP(47, 200, 46, 0xC4, 32);
                putSP(48, 176, 54, 0xD2, 32);
                putSP(49, 184, 54, 0xD3, 32);
                putSP(50, 192, 54, 0xD3, 32);
                putSP(51, 200, 54, 0xD4, 32);
            }
        }
        while (win_map_flag == 1) {
            if (display_flag == 1) {
                disable_graphics();
                load_full_name_0((u8*)win_map);
                load_BG_palette((u8*)win_col);
                load_SP_palette((u8*)win_col);
                enable_graphics();
                wait_VBlank();
            }
            display_flag = 0;
            address(PPU_ctrl_reg_2) = REG_2_IM_able;
            address(PPU_ctrl_reg_2+1) = 0;
        }
        while (fail_map_flag == 1) {
            if (display_flag == 1) {
                disable_graphics();
                load_full_name_0((u8*)fail_map);
                load_BG_palette((u8*)fail_col);
                load_SP_palette((u8*)fail_col);
                enable_graphics();
                wait_VBlank();
            }
            display_flag = 0;
            address(PPU_ctrl_reg_2) = REG_2_IM_able;
            address(PPU_ctrl_reg_2+1) = 0;
        }
    }
}