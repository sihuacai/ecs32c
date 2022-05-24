#include <stdio.h>
#include <string.h> 
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc < 2) 
    {
        fprintf(stderr, "No file provided.\n"); 
        return 2;
    }
    
    FILE* fp; 
    
    int t_chars = 0; 
    int t_words = 0; 
    int t_lines = 0; 

    int flags = 0;
    int cannot_open = 0;
    int print_l = 0;
    int print_w = 0; 
    int print_c = 0; 

    for (int i = 1; i < argc; i++) 
    {
        // check if is flag
        if (argv[i][0] == '-')
        {
            flags = 1;
            if (!strcmp(argv[i], "--lines"))
                print_l = 1; 
            if (!strcmp(argv[i], "--words"))
                print_w = 1; 
            if (!strcmp(argv[i], "--chars"))
                print_c = 1;
            else
            {
                for (unsigned j = 1; j < strlen(argv[i]); j++)
                {
                    if (argv[i][j] == 'l') 
                        print_l = 1; 
                    if (argv[i][j] == 'w') 
                        print_w = 1; 
                    if (argv[i][j] == 'm') 
                        print_c = 1; 
                }
            }
        }

        // all other command line arguments should, 
        // in theory, be file names. 

        // if file cannot be opened: 
        else if ((fp = fopen(argv[i], "r")) == NULL)
        // if statement condition reference:
        // https://stackoverflow.com/questions/18937861
        // c how to take multiple files for arguments
        {
            perror("fopen");
            //printf("fopen: No such file or directory.");
            cannot_open = 1; 
        }
        
        // else file can be opened: 
        else 
        {
            fp = fopen(argv[i], "r"); 
            
            int lines = 0; 
            int words = 0; 
            int chars = 0; 

            char ch = fgetc(fp); 
            char prev = '0'; 

            while (ch != EOF) 
            {   

                chars++; 
                if (ch == '\n') 
                    lines++; 
                if (isspace(prev) && !isspace(ch))
                    words++; 

                prev = ch; 
                ch = fgetc(fp);
                
            }

            if (chars > 1) 
                words++; 
           
            t_lines += lines; 
            t_words += words; 
            t_chars += chars;

            // if no flags were given,
            // set all print booleans to true. 
            if (!flags) 
            {
                print_l = 1; 
                print_w = 1; 
                print_c = 1; 
            }

            printf("%s: ", argv[i]);
            if (print_l) 
                printf("%d ", lines); 
            if (print_w)
                printf("%d ", words); 
            if (print_c)
                printf("%d ", chars); 
            printf("\n");
     
        }
    }   

    if (argc > 2)
    {
        printf("total: "); 
        if (print_l) 
            printf("%d ", t_lines); 
        if (print_w)
            printf("%d ", t_words); 
        if (print_c)
            printf("%d ", t_chars); 
        printf("\n");

    }
    
    if (cannot_open)
        return 1;
    return 0;
}
