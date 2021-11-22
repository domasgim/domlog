#include <argp.h>
#include <stdio.h>
#include <libdomlog.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

/* Program documentation. */
static char doc[] =
  "domlog -- a program which shows logs used from libdomlog logging library";

/* The options we understand. */
static struct argp_option options[] = {
  {"program",  'p', "NAME",      0,  "Program name" },
  { 0 }
};

/* Used by main to communicate with parse_opt. */
struct arguments {
  char *program_name;
  int program_name_flag;
};

/* Parse a single option. */
static error_t parse_opt (int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input;

    switch (key) {
        case 'p':
            arguments->program_name = arg;
            arguments->program_name_flag = 1;
            break;
        case ARGP_KEY_END:
        break;
        default:
            return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

/* argp parser. */
static struct argp argp = { options, parse_opt, 0, doc };