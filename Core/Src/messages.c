/*

File:   messages.c
Author: Isaac Pawley

*/

#include "messages.h"

#ifndef __weak
#define __weak __attribute__((weak))
#endif

__weak const char *messages[] = {
    "uAffirmations - A microcontroller-based affection-giving MACHINE!",
    "Whoops, it looks like you forgot to add you own messages!",
    "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
};

__weak size_t number_of_messages = sizeof(messages) / sizeof(messages[0]);