#ifndef GLOBAL_VM_H
#define GLOBAL_VM_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "../VirtualContext/List.h"
#include "../VirtualContext/Fnv1a.h"

#define STRING_MAX_LENGTH	256

#include "../VirtualContext//IdeAPI.h"
#include "../VirtualContext/Defenitions.h"
#include "../VirtualContext/HashTable.h"
#include "../VirtualContext/PMC.h"
#include "../VirtualContext/VirtualContext.h"

#include "Operations.h"
#include "Runtime.h"
#include "VmService.h"

#endif