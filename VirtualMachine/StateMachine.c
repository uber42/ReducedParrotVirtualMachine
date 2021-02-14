#include "global.h"


static const SStateMahcineCommand commands[][16] =
{
	{ 0 ,	"new",		0x28999611 },
	{ 1 ,	"set",		0xC6270703 },

	{ 2 ,	"inc",		0xA8E99C47 },
	{ 3 ,	"dec",		0xC25979D3 },
	{ 4 ,	"add",		0x3B391274 },
	{ 5 ,	"sub",		0xDC4E3915 },
	{ 6 ,	"mul",		0xEB84ED81 },
	{ 7 ,	"div",		0xE562AB48 },

	{ 8 ,	"length",	0x83D03615 },
	{ 9 ,	"concat",	0xF5CF8C7D },
	{ 10 ,	"substr",	0x4981C820 },

	{ 11 ,	"branch",	0xB6873945 },
	{ 12 ,	"if",		0x39386E06 },
	{ 13 ,	"ne",		0x5836603C },
	{ 14 ,	"eq",		0x441A6A43 },
	{ 15 ,	"gt",		0x4B208576 },
	{ 16 ,	"lt",		0x5D31EAED },

	{ 17 ,	"bsr",		0x5EE476F0 },
	{ -1 ,	"ret",		0x30F467AC },

	{ 18 ,	"print",	0x16378A88 },

	{ 19 ,	"push",		0x876FFFDD },
	{ 20 ,	"pop",		0x51335FD0 },

	{ -1 ,	"end",		0x6A8E75AA }
};


static const SStateMachineTransition transition_1[] =
{
	{ EMT_P,					0,		0,		0	},
	{ ALL_MEMORY_MASK,			1,		-1,		0	},

	{ EMT_I | EMT_N | EMT_P,	-1,		1,		1	},
	{ EMT_I | EMT_N | EMT_P,	-1,		1,		1	},
	{ EMT_I | EMT_N | EMT_P,	2,		2,		0	},
	{ EMT_I | EMT_N | EMT_P,	3,		3,		0	},
	{ EMT_I | EMT_N | EMT_P,	4,		4,		0	},
	{ EMT_I | EMT_N | EMT_P,	5,		5,		0	},

	{ EMT_S | EMT_P,			-1,		6,		1	},
	{ EMT_S | EMT_P,			6,		7,		0	},
	{ EMT_S | EMT_P,			7,		8,		0	},

	{ EMT_MARKER,				-1,		9,		1	},
	{ EMT_I,					8,		10,		0	},
	{ REGISTERS_MASK,			9,		11,		0	},
	{ REGISTERS_MASK,			9,		11,		0	},
	{ REGISTERS_MASK,			9,		11,		0	},
	{ REGISTERS_MASK,			9,		11,		0	},

	{ EMT_MARKER,				-1,		9,		1	},

	{ REGISTERS_AND_LITERAL,	-1,		12,		1	},

	{ REGISTERS_AND_LITERAL,	-1,		13,		1	},
	{ REGISTERS_MASK,			-1,		13,		1	},
};

static const char errorMessages[][STRING_MAX_LENGTH] =
{
	"������� new ������������� ������ ��� �������� P",

	"��������� ������������ ������ ��� �������� ���������",
	"��������� ������������ ������ ��� �������� ���������",
	"�������� ����������� ������ ��� �������� ��������",
	"��������� ����������� ������ ��� �������� ��������",
	"��������� ����������� ������ ��� �������� ��������",
	"������� ����������� ������ ��� �������� ��������",

	"����� ����������� ������ ��� �����",
	"������������ ����������� ������ ��� �����",
	"�������� ��������� ����� ��������� ������ ������ ��� ���������",

	"������ ���� ������� �����",
	"��� ������� ����������� ������������� ��������",
	"��� ������� ����� ����������� ������ �������",

	"� ���� ����� �������� ������ �������� ��� �������",
	"�� ����� ����� �������� ������ � �������"
}