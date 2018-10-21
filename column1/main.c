#include <stdio.h>
#include <stdlib.h>
#define CODE_MAX 10000000
#define SLOT_SIZE sizeof(int)
#define PHONE_CODE_DIGIT 7
#define STATE_ARR_LENGTH CODE_MAX / SLOT_SIZE
#define READ_LENGTH PHONE_CODE_DIGIT + 1
#define BASE_OF_SHIFT 1

void
find_index(int *tuple, int x)
{
  tuple[0] = x / SLOT_SIZE;
  tuple[1] = x % SLOT_SIZE;
}

void
update_state(int *state, int idx, int value)
{
  int point, focus;
  point = BASE_OF_SHIFT << (value - 1);
  focus = state[idx];
  state[idx] = focus | point;
}

int
main (void)
{
  int state[STATE_ARR_LENGTH];
  int tuple[2];
  char buf[PHONE_CODE_DIGIT];
  int current, state_idx, state_rem;

  FILE *input;
  //input = fdopen(0, "r");
  input = fopen("./test.txt", "r");

  if (input == NULL) {
    printf("Can not open stdin");
    return 1;
  }

  printf("start loop");
  while (fgets(buf, READ_LENGTH, input) != NULL) {
    printf("buf: %s", buf);
    current = atoi(buf);
    printf("current: %d", current);
    find_index(tuple, current);
    state_idx = tuple[0];
    state_rem = tuple[1];
    printf("idx: %d", state_idx);
    printf("rem: %d", state_rem);
    update_state(state, state_idx, state_rem);

    printf("state_focus: %d at %d\n", state[state_idx], state_idx);
  }
  fclose(input);

  return 0;
}
