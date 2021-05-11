#include "stdio.h"

int main()
{
    size_t rows;
    size_t columns;

    scanf("%zu%zu", &rows, &columns);

    unsigned int counter = 0;

    while (rows != 0 || columns != 0)
    {
        counter += 1;

        char field[rows][columns];

        for (size_t r = 0; r < rows; r++)
        {
            scanf("\n");

            for (size_t c = 0; c < columns; c++)
                field[r][c] = getchar();
        }

        printf("Field #%u:\n", counter);

        for (size_t r = 0; r < rows; r++)
        {
            for (size_t c = 0; c < columns; c++)
            {
                if (field[r][c] == 42)
                    printf("%s", "*");
                else
                {
                    unsigned int adjacentMines = 0;

                    for (size_t adjacentRow = r == 0 ? r : r - 1; adjacentRow <= (r == rows - 1 ? r : r + 1); adjacentRow++)
                        for (size_t adjacentColumn = c == 0 ? c : c - 1; adjacentColumn <= (c == columns - 1 ? c : c + 1); adjacentColumn++)
                            if (field[adjacentRow][adjacentColumn] == 42)
                                adjacentMines += 1;

                    printf("%u", adjacentMines);
                }
            }

            puts("");
        }

        scanf("%zu%zu", &rows, &columns);
    }

    return 0;
}
