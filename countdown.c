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
 */

#include <stdio.h>
#include <time.h>
#define BUF_LEN 1024
#define MAX_NUMS 6

int count_nums(int a, int *b, int len);

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
      while (1) {
        z = numbers[rand() % MAX_NUMS];
        if (count_nums(z, used, u) < count_nums(z, numbers, MAX_NUMS))
          break;
      }
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
        if (o > 0 && z == 1 && (ops[ups[o-1]] == '*' || ops[ups[o-1]] == '/')) {
          o--;
          u--;
        }
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

int count_nums(int a, int *b, int len) {
  int i, count = 0;
  for (i = 0; i < len ; i++)
    if (a == b[i]) 
      count++;
  return count;
}
