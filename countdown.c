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

int is_num_idle(int a, int *b, int len);

int main() {
  srand(time(0));
  int i, u = 0, r, o = 0, target, previous, current = 0;
  int numbers[MAX_NUMS], used[MAX_NUMS];
  char ops[] = "+-*/";
  int ups[MAX_NUMS];
  char buffer[BUF_LEN];
  
  for (i = 0; i < MAX_NUMS; i++) {
    scanf("%d", &numbers[i]);
    used[i] = -1;
  }
  scanf("%s", buffer);
  scanf("%d", &target);
  
  while (current != target) {
    if (u < MAX_NUMS) {
      while (is_num_idle(numbers[r = rand() % MAX_NUMS], used, u) == 0) {}
      used[u] = numbers[r];
      if (current == 0)
        current = used[u];
      else {    
        switch (ops[r = rand() % 4]) {
          case '+': current += used[u]; break;
          case '-': current -= used[u]; break;
          case '*': current *= used[u]; break;
          case '/': 
            previous = current;
            current /= used[u];
            if (current * used[u] != previous)
              current = u = o = 0;
            break;
        }
        ups[o++] = r;
      }
      u++;
    }
    else if (u >= MAX_NUMS)
      current = u = o = 0;
    if (current < 0)
      current = u = o = 0;
  }
  /*printf("((((%d %c %d) %c %d) %c %d) %c %d) %c %d \n= %d\n",*/
  printf("%d %c %d %c %d %c %d %c %d %c %d \n= %d\n",
    used[0], ops[ups[0]],
    used[1], ops[ups[1]],
    used[2], ops[ups[2]],
    used[3], ops[ups[3]],
    used[4], ops[ups[4]],
    used[5], current
  );
  return 0;
}

int is_num_idle(int a, int *b, int len) {
  int i;
  for (i = 0; i < len; i++)
    if (a == b[i]) return 0;
  return 1;
}
