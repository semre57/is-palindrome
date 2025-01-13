//
// Created by Emre Ağan on 13.01.2025.
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

int main()
{
    char str [SIZE];
    printf("Enter a string: ");
    if (fgets(str, SIZE, stdin) != NULL) {
        // fgets, satır sonu karakterini (\n) de alır, bunu kaldırmak isterseniz:
        str[strcspn(str, "\n")] = '\0';  // Satır sonu karakterini null ile değiştiriyoruz
    }

    int len;
    for(len = 0; str[len]; len++) // str[len] means => (str[len] != '\0') also ('\0')'s ASCII is 0.
        ; //null statement        // remember: in c language, non-zero values means true.

    int l_ind = 0; // left index
    int r_ind = len-1; // right index
    int flag = 0;

    char control[6] = {'!','?','.',',','\'',' '}; // we need to control elements of that array.

    for(int i = 0; (i<len) && (l_ind<=r_ind); i++) {

        for (int j=0; j<6; j++)

            for(int k=0;k<6;k++) {

                while(str[l_ind] == control[k])
                    ++l_ind;

                while(str[r_ind] == control[k])
                    --r_ind;
            }

        if(tolower((int)str[l_ind++])  != tolower((int)str[r_ind--]))
            flag++;

    }

    if (!flag)
        printf("%s is palindrome!",str);
    else
        printf("%s is not palindrome.",str);
}
