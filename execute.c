#include "monty.h"

/**
 * executeOpCodes - Executes the Monty opcodes
 * @lines: Array of opcode lines
 * @stack: The stack
 * Return: Void
 */
void executeOpCodes(char *lines[], stack_t *stack)
{
	int lineNum, opcodeIndex;

	instruction_t instructions[] = {
		{"pall", myPall},
		{"pint", myPint},
		{"pop", myPop},
		{"swap", mySwap},
		{"add", myAdd}
		/* will add some more instructions here */
	};

	for (lineNum = 1; lines[lineNum - 1]; lineNum++)
	{
		if (compareStrings("push", lines[lineNum - 1]))
			myPush(&stack, lineNum, getIntFromPush(lines[lineNum - 1], lineNum));
		else if (compareStrings("nop", lines[lineNum - 1]))
			;
		else
		{
			opcodeIndex = 0;
			while (instructions[opcodeIndex].opcode)
			{
				if (compareStrings(instructions[opcodeIndex].opcode, lines[lineNum - 1]))
				{
					instructions[opcodeIndex].f(&stack, lineNum);
					break;
				}
				opcodeIndex++;
			}
			if (!instructions[opcodeIndex].opcode && !compareStrings(lines[lineNum - 1], "\n"))
			{
				fprintf(stderr, "L%u: Unknown instruction ? %s", lineNum, lines[lineNum - 1]);
				if (!findNewline(lines[lineNum - 1]))
					fprintf(stderr, "\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
