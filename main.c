#include <stdio.h>

#define CIRCLE_RADIUS 20

int circle[CIRCLE_RADIUS * 2][CIRCLE_RADIUS * 2] = {0};

void render_circle() {

  for (int x = 0; x <= CIRCLE_RADIUS * 2; x++) {
    for (int y = 0; y <= CIRCLE_RADIUS * 2; y++) {
      int dx = CIRCLE_RADIUS - x;
      int dy = CIRCLE_RADIUS - y;

      if ((dx*dx) + (dy*dy) <= (CIRCLE_RADIUS*CIRCLE_RADIUS)) {
        circle[x][y] = 1;
      } else {
        circle[x][y] = 0;
      }
    }
  }

  char table[2][2] = {
    [0][0] = ' ',
    [0][1] = '_',
    [1][0] = '`',
    [1][1] = '@',
  };
  
  for (int x = 0; x <= CIRCLE_RADIUS * 2; x += 2) {
    for (int y = 0; y <= CIRCLE_RADIUS * 2; y++) {
      int up = circle[x][y];
      int down = circle[x + 1][y];
      
      char value = table[up][down];

      printf("%c", value);
    }
    printf("\n");
  }
}

int main(void) {
  render_circle();
  return 0;
}
