#include<stdio.h>
#include<windows.h>

void gotoxy(int x, int y)
  {
   COORD coord;
   coord.X = x; coord.Y = y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
  }
int lrow=0, lcol=0;



void insertValue(int r, int c, char v)
{
char Editor[lrow][lcol];

    int width=0;
    char line[40];
    FILE *fptr;
    fptr = fopen("C://file//file_contents.txt", "a");
    if(fptr == NULL)
    {
        printf("Error somewhere!!");
        exit(1);
    }
    for(int i=0;i<lrow;i++){
        for(int j=0;j<lcol;j++)
        {
            if(v =='\0')
            {
                fprintf(fptr,"/0"); //add a space before ending a line;
                if(r == lrow)  //update last row if last row becomes == inserting row and enter is pressed
                {
                lrow++;
                }
                //break;
            }
            if((i==r)&&(j==r)){
                Editor[r][c] = v;
            }

            //printf("Reached Here;D");
            line[j]=Editor[i][j];
            if(c == lcol)
            {
                lcol++; //update last col if last row becomes == inserting col and there's a value to input
            }
                width++;
        }
        width=0;
    }
    fprintf(fptr,"%c",v);
    fclose(fptr);
}

int trackWidthLength (int trackrow[], int maxColumns)
{
    int w=0;
    for(int a=0; a<maxColumns; a++)
        {
            if(trackrow[a] != '\n')
            {
                w++;
            }
        }
    return w;
}

int isEmptyLine()
{
}

int main() {
int key;
int row=0,col=0;
    while (key!=27) {
        if (_kbhit()) {
           key=_getch();
           //printf("%d",key);
                if (key == 224) {
                    do {
                        key=_getch();
                       // printf("%d", key);
                    } while(key==224);
                        switch (key) {
                            case 72:
                                //printf("up");
                                //trackWidthLength (int trackrow[], int maxColumns)
                                //if(trackWidthLength(row--,lcol)>= col){
                                    row--;
                                    gotoxy(col,row);
                                //}else{
                                    //row--;
                                   // gotoxy(row,trackWidthLength(row--,lcol));
                                //}

                            break;
                            case 75:
                                //printf("left");
                                col--;
                                gotoxy(col,row);
                            break;
                            case 77:
                                if(col < lcol){
                                        col++;
                                    gotoxy(col,row);
                                }
                                else{

                                    gotoxy(col,row);
                                }
                                //printf("right");
                            break;
                            case 80:
                                if(row==lrow){
                                    gotoxy(col,row);
                                }
                                else
                                    {
                                        row++;
                                        gotoxy(col,row);
                                    }
                                //printf("down");
                            break;

                        }
            }

            else if(key==8){
               col--;
               gotoxy(col,row);
               printf(" ");
               gotoxy(col-1,row);
            }
            else if(key==13){
                insertValue(row,col,'\n');
                if(row==lrow)
                    {
                        lrow++;
                    }
                row++;
                col=0;
                gotoxy(col,row);
