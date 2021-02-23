#ifndef GLOBAL_H
#define GLOBAL_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "List.h"
#include "Fnv1a.h"

#define STRING_MAX_LENGTH	256

#include "PMC.h"
#include "VirtualContext.h"
#include "Token.h"
#include "Lexer.h"
#include "StateMachine.h"
#include "Compiler.h"

#include "LexerTest.h"
#include "StateMachineTest.h"

#endif