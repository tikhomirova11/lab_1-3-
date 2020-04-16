#include "func.h"


int main()
{
    struct persone *list;  // указатель на массив
    int  i, n, j, k;
    system("chcp 1251");
    system("cls");
    printf("Здравствуйте! Необходимо заполнить исходный массив. \nВведите кол-во студентов: ");
    scanf ("%d", &n); 
    if (n == 0)
    {
        while (n == 0)
        {
            printf("Запрос не имеет смысла, повторите попытку ввода");
            scanf("%d", &n);
        }
    }
    list = (struct persone*)malloc(n * sizeof(struct persone)); // Выделение памяти

    printf("Введите данные:");
    input(list,n);
    printf("Вы ввели:");
    output(list, n);
    
    do
    {
        printf("\n Вы хотели бы использовать какие-либо операции над списком? Введите 1, если хотели бы, и 0, если нет.\n");
        scanf("%d", &k);

        if (k == 1)
        {
            printf("\n1.Операция map \n2.Операция where \n3.Операция конкатинация \n4. Если есть z в фамилии - поменять дату на 1 апреля \n 5. Если есть z - подходит\n Введите 1, 2, 3 или 4\n");
            scanf("%d", &j);

            if (j == 1)  map(list, n, toFebruary);

            if (j == 2)  where(list, n, AfterMay);

            if (j == 3)  concat(list, n);

            if (j == 4)  map(list, n, FuncApril); 

            if (j == 5) where(list, n, FuncAprilForWhere);
        }  

        else if (k == 0)
        {
            printf("Спасибо, что воспользовались программой! Нажмите Enter");
            break;
        }

        else
        {
            while (k < 0 || k >1)
            {
                printf("Значение введено неверно, попробуйте еще раз.");
                scanf("%d", &k);
            }
        }
    } 
    while (k == 1);


    getchar(); 
    getchar();
    return 0;
}
