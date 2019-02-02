#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	char c;

	printf("enter character: ");
	scanf(" %c", &c);
	printf("\n");
	switch (c)
	{
		case 65: //A
		case 97: //a
		printf("input is 'a' or 'A'");
		break;

		case 66: //B
		case 98: //b
		printf("input is 'b' or 'B'");
		break;

		case 67: //C
		case 99: //c
		printf("input is 'c' or 'C'");
		break;
		case 68: //D
		case 100: //d
		printf("input is 'd' or 'D'");
		break;

		case 69:  //E
		case 101: //e
		printf("input is 'e' or 'E'");
		break;

		case 70: //F
		case 102: //f
		printf("input is 'f' or 'F'");
		break;

		case 71:  //G
		case 103: //g
		printf("input is 'g' or 'G'");
		break;

		case 72:  //H
		case 104: //h
		printf("input is 'h' or 'H'");
		break;

		case 73: //I
		case 105: //i
		printf("input is 'i' or 'I'");
		break;

		case 74: //J
		case 106: //j
		printf("input is 'j' or 'J'");
		break;

		case 75: //K
		case 107: //k
		printf("input is 'k' or 'K'");
		break;

		case 76: //L
		case 108: //l
		printf("input is 'l' or 'L'");
		break;

		case 77: //M
		case 109: //m
		printf("input is 'm' or 'M'");
		break;

		case 78: //N
		case 110: //n
		printf("input is 'n' or 'N'");
		break;

		case 79: //O
		case 111: //o
		printf("input is 'o' or 'O'");
		break;

		case 80: //P
		case 112: //p
		printf("input is 'p' or 'P'");
		break;

		case 81: //Q
		case 113: //q
		printf("input is 'q' or 'Q'");
		break;

		case 82: //R
		case 114: //r
		printf("input is 'r' or 'R'");
		break;

		case 83: //S
		case 115: //s
		printf("input is 's' or 'S'");
		break;

		case 84: //T
		case 116: //t
		printf("input is 't' or 'T'");
		break;

		case 85: //U
		case 117: //u
		printf("input is 'u' or 'U'");
		break;

		case 86: //V
		case 118: //v
		printf("input is 'v' or 'V'");
		break;

		case 87: //W
		case 119: //w
		printf("input is 'w' or 'W'");
		break;

		case 88: //X 
		case 120: //x
		printf("input is 'x' or 'X'");
		break;

		case 89: //Y
		case 121: //y
		printf("input is 'y' or 'Y'");
		break;

		case 90: //Z
		case 122: //x
		printf("input is 'z' or 'Z'");
		break;
		
		default:
		break;
	}

	printf("\n");
	return 0;
}
