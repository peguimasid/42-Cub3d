/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:25:36 by gmasid            #+#    #+#             */
/*   Updated: 2023/03/07 12:21:20 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int worldMap[24][24] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 4, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void verLine(t_game *game, int x, int y1, int y2, int color) {
  int y;

  y = y1;
  while (y <= y2) {
    mlx_pixel_put(game->mlx, game->win, x, y, color);
    y++;
  }
}

void calc(t_game *game) {
  int x;
  double cameraX;
  double rayDirX;
  double rayDirY;
  int mapX;
  int mapY;
  double sideDistX;
  double sideDistY;
  double deltaDistX;
  double deltaDistY;
  double perpWallDist;
  int stepX;
  int stepY;
  int lineHeight;
  int drawStart;
  int drawEnd;
  int color;

  x = 0;
  while (x < WINDOW_WIDTH) {
    cameraX = 2 * x / (double)WINDOW_WIDTH - 1;
    rayDirX = game->dirX + game->planeX * cameraX;
    rayDirY = game->dirY + game->planeY * cameraX;
    mapX = (int)game->posX;
    mapY = (int)game->posY;
    // length of ray from current position to next x or y-side
    // length of ray from one x or y-side to next x or y-side
    deltaDistX = fabs(1 / rayDirX);
    deltaDistY = fabs(1 / rayDirY);
    // what direction to step in x or y-direction (either +1 or -1)
    int hit = 0;  // was there a wall hit?
    int side;     // was a NS or a EW wall hit?
    if (rayDirX < 0) {
      stepX = -1;
      sideDistX = (game->posX - mapX) * deltaDistX;
    } else {
      stepX = 1;
      sideDistX = (mapX + 1.0 - game->posX) * deltaDistX;
    }
    if (rayDirY < 0) {
      stepY = -1;
      sideDistY = (game->posY - mapY) * deltaDistY;
    } else {
      stepY = 1;
      sideDistY = (mapY + 1.0 - game->posY) * deltaDistY;
    }
    while (hit == 0) {
      // jump to next map square, OR in x-direction, OR in y-direction
      if (sideDistX < sideDistY) {
        sideDistX += deltaDistX;
        mapX += stepX;
        side = 0;
      } else {
        sideDistY += deltaDistY;
        mapY += stepY;
        side = 1;
      }
      // Check if ray has hit a wall
      if (worldMap[mapX][mapY] > 0)
        hit = 1;
    }
    if (side == 0)
      perpWallDist = (mapX - game->posX + (1 - stepX) / 2) / rayDirX;
    else
      perpWallDist = (mapY - game->posY + (1 - stepY) / 2) / rayDirY;
    lineHeight = (int)(WINDOW_HEIGHT / perpWallDist);

    // start of line
    drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2;
    if (drawStart < 0) drawStart = 0;
    // end of line
    drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2;
    if (drawEnd >= WINDOW_HEIGHT) drawEnd = WINDOW_HEIGHT - 1;

    color = 0xFFFF00;
    if (worldMap[mapY][mapX] == 1) color = 0xFF0000;
    if (worldMap[mapY][mapX] == 2) color = 0x00FF00;
    if (worldMap[mapY][mapX] == 3) color = 0x0000FF;
    if (worldMap[mapY][mapX] == 4) color = 0xFFFFFF;
    if (side == 1) color = color / 2;

    verLine(game, x, drawStart, drawEnd, color);
    x++;
  }
}

int handle_keys(t_game *game) {
  double oldDirX;
  double oldPlaneX;

  if (game->keys.is_w_pressed) {
    if (!worldMap[(int)(game->posX + game->dirX * game->moveSpeed)][(int)(game->posY)])
      game->posX += game->dirX * game->moveSpeed;
    if (!worldMap[(int)(game->posX)][(int)(game->posY + game->dirY * game->moveSpeed)])
      game->posY += game->dirY * game->moveSpeed;
  }
  // move backwards if no wall behind you
  if (game->keys.is_s_pressed) {
    if (!worldMap[(int)(game->posX - game->dirX * game->moveSpeed)][(int)(game->posY)])
      game->posX -= game->dirX * game->moveSpeed;
    if (!worldMap[(int)(game->posX)][(int)(game->posY - game->dirY * game->moveSpeed)])
      game->posY -= game->dirY * game->moveSpeed;
  }
  // rotate to the right
  if (game->keys.is_d_pressed) {
    // both camera direction and camera plane must be rotated
    oldDirX = game->dirX;
    game->dirX = game->dirX * cos(-game->rotationSpeed) - game->dirY * sin(-game->rotationSpeed);
    game->dirY = oldDirX * sin(-game->rotationSpeed) + game->dirY * cos(-game->rotationSpeed);
    oldPlaneX = game->planeX;
    game->planeX = game->planeX * cos(-game->rotationSpeed) - game->planeY * sin(-game->rotationSpeed);
    game->planeY = oldPlaneX * sin(-game->rotationSpeed) + game->planeY * cos(-game->rotationSpeed);
  }
  // rotate to the left
  if (game->keys.is_a_pressed) {
    // both camera direction and camera plane must be rotated
    oldDirX = game->dirX;
    game->dirX = game->dirX * cos(game->rotationSpeed) - game->dirY * sin(game->rotationSpeed);
    game->dirY = oldDirX * sin(game->rotationSpeed) + game->dirY * cos(game->rotationSpeed);
    oldPlaneX = game->planeX;
    game->planeX = game->planeX * cos(game->rotationSpeed) - game->planeY * sin(game->rotationSpeed);
    game->planeY = oldPlaneX * sin(game->rotationSpeed) + game->planeY * cos(game->rotationSpeed);
  }
  return (0);
}

int main_loop(t_game *game) {
  mlx_clear_window(game->mlx, game->win);
  handle_keys(game);
  calc(game);
  return (0);
}

int key_down(int key, t_game *game) {
  if (key == KEY_W) game->keys.is_w_pressed = 1;
  if (key == KEY_A) game->keys.is_a_pressed = 1;
  if (key == KEY_S) game->keys.is_s_pressed = 1;
  if (key == KEY_D) game->keys.is_d_pressed = 1;
  return 0;
}

int key_up(int key, t_game *game) {
  if (key == KEY_W) game->keys.is_w_pressed = 0;
  if (key == KEY_A) game->keys.is_a_pressed = 0;
  if (key == KEY_S) game->keys.is_s_pressed = 0;
  if (key == KEY_D) game->keys.is_d_pressed = 0;
  return 0;
}

void set_game_config(t_game *game) {
  game->mlx = mlx_init();
  game->posX = 12;
  game->posY = 5;
  game->dirX = -1;
  game->dirY = 0;
  game->planeX = 0;
  game->planeY = 0.66;
  game->moveSpeed = 0.25;
  game->rotationSpeed = 0.10;
  game->keys.is_w_pressed = 0;
  game->keys.is_a_pressed = 0;
  game->keys.is_s_pressed = 0;
  game->keys.is_d_pressed = 0;
  game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx");
}

int main(void) {
  t_game game;

  set_game_config(&game);
  mlx_loop_hook(game.mlx, &main_loop, &game);
  mlx_hook(game.win, ON_KEYDOWN, 0, &key_down, &game);
  mlx_hook(game.win, ON_KEYUP, 0, &key_up, &game);
  mlx_loop(game.mlx);
}
