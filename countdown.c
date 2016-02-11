/* countdown.c */

/**
 *
 * @author __MadHatter (alias used on https://www.reddit.com/r/dailyprogrammer)
 *
 * [2016-02-10] Challenge #253 [Intermediate] Countdown (numbers game)
 * https://www.reddit.com/r/dailyprogrammer/comments/452omr/20160210_challenge_253_intermediate_countdown/
 *
 *
 * In C. First countdown only. Runs the sample and challenge inputs "instantly" 
 * despite having no smart algorithm. The algorithm only tests random numbers and 
 * operators. Written purposely with almost zero effort for 
 * documentation/legibility. Comments/criticism/questions are welcome.
 *
 * Edit (2016/02/11): fixed an output bug that would display bogus extra 
 * numbers from previous attempts if a solution did not use all 6 numbers 
 * (array printing issue). Fixed version e.g.
 *
 *   > ./countdown
 *   4 1 2 8 75 25 makes 527
 *   8 - 1 * 75 + 2
 *   = 527
 */

#include <stdio.h>
#include <time.h>
#define BUF_LEN 1024
#define MAX_NUMS 6

int is_num_idle(int a, int *b, int len);

int main() {
  srand(time(0));
  int i, z, u = 0, r, o = 0, target, current = 0;
  int numbers[MAX_NUMS], used[MAX_NUMS];
  char ops[] = "+-*/";
  int ups[MAX_NUMS];
  char buffer[BUF_LEN];

  for (i = 0; i < MAX_NUMS; i++) {
    scanf("%d", &numbers[i]);
    
  }
  scanf("%s", buffer);
  scanf("%d", &target);
  for (i = 0; i < MAX_NUMS; i++) {
    used[i] = 0;
  }

  while (current != target)
  {
    if (u < MAX_NUMS) {
      while (is_num_idle(numbers[r = rand() % MAX_NUMS], used, u) == 0) {}
      z = numbers[r];
      used[u++] = z;
      if (current == 0)
        current = z;
      else {    
        switch (ops[r = rand() % 4]) {
          case '+': current += z; break;
          case '-': current -= z; break;
          case '*': current *= z; break;
          case '/': 
            if (z < current 
                && (current % z) == 0)
              current /= z;
            else
              current = u = o = 0;
            break;
        }
        ups[o++] = r;
      }
    }
    else if (u >= MAX_NUMS)
      current = u = o = 0;
    if (current <= 0)
      current = u = o = 0;
  }
  
  for (i = 0; i < u-1; i++){
    printf("%d %c ", used[i], ops[ups[i]]);
  }
  printf("%d\n= %d\n", used[i], current);

  return 0;
}

int is_num_idle(int a, int *b, int len) {
  int i;
  for (i = 0; i < len; i++)
    if (a == b[i]) return 0;
  return 1;
}
