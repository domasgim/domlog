#include "domlog.h"

int main(int argc, char **argv) {
    struct arguments arguments;
    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    if(arguments.program_name_flag) {
        domlog_print(arguments.program_name);
    } else {
        domlog_print(NULL);
    }
    return 0;
}