#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
    FILE *fp;
    int i, addr1, l, j, staddr1;
    char name[10], name2[10], len[10], line[1000], name1[10], addr[10], rec[10], ch, staddr[10];
    fp = fopen("code.txt", "r");
    fscanf(fp, "%s", line);
    int count = 0, a = 0, b = 0, c = 0;
    for (i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == '^')
        {
            count++;
            continue;
        }
        if (count == 1)
        {
            name1[a] = line[i];
            a++;
        }
        else if (count == 2)
        {
            name2[b] = line[i];
            b++;
        }
        else if (count == 3)
        {
            len[c] = line[i];
            c++;
        }
    }

    name1[a] = '\0';
    name2[b] = '\0';
    len[c] = '\0';
    printf("%s\t", name1);
    printf("Starting Add : %s\t", name2);
    printf("Length : %s\n\n", len);
    do
    {
        fscanf(fp, "%s", line);
        if (line[0] == 'T')
        {
            count = 0;
            a = 0;
            for (i = 0; line[i] != '\0'; i++)
            {
                if (line[i] == '^')
                {
                    count++;
                    continue;

                }
                if (count == 1)
                {
                    staddr[a] = line[i];
                    a++;
                }
                else if (count == 3)
                {
                    break;
                }
            }
            staddr[a] = '\0';
            staddr1 = strtol(staddr, NULL, 16);

            while (line[i] != '\0')
            {
                if (line[i] != '^')
                {
                    int aa, bb;
                    aa = line[i];
                    bb = line[i + 1];
                    aa -= 48;
                    bb -= 48;
                    if (aa > 10)
                    {
                        aa -= 7;
                    }
                    if (bb > 10)
                    {
                        bb -= 7;
                    }
                    int cc = aa * 16 + bb;

                    printf("00%X \t %02X\n", staddr1, cc);
                    staddr1++;
                    i = i + 2;
                }
                else
                    i++;
            }
        }
        else if (line[0] = 'E')
        {
            break;
        }
    } while (!feof(fp));
}
/*
H^COPY^001000^00107A
T^001000^1E^141033^482039^001036^281030^301015^482061^3C1003^00102A^0C1039^00102D
T^00101E^15^0C1036^482061^081033^4C0000^454F46^000003^000000
T^001047^1E^041030^001030^E0205D^30203F^D8205D^281030^302057^549039^2C205E^38203F
T^001077^1C^101036^4C0000^000000^001000^041030^E02079^302064^509039^DC2079^2C1036
E^001000
*/