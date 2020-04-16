#include "func.h"


void* input(persone* list, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\nВведите Person ID\nСерия :");
        scanf("%d", &(list + i)->id.seria);
        printf("Номер : ");
        scanf("%d", &(list + i)->id.nomer);
        printf("Введите имя : ");
        scanf("%s", (list + i)->firstname);
        printf("Введите фамилию : ");
        scanf("%s", (list + i)->lastname);
        printf("Введите дату рождения\nЧисло: ");
        scanf("%d", &(list + i)->bd.date);
        if ((list + i)->bd.date > 31)
        {
            while ((list + i)->bd.date > 31)
            {
                printf("Вы ввели неправельный формат даты. Введите, пожалуйста, еще раз.\n");
                scanf("%d", &(list + i)->bd.date);
            }
        }
        printf("Месяц: ");
        scanf("%d", &(list + i)->bd.month);
        if ((list + i)->bd.month > 12)
        {
            while ((list + i)->bd.month > 12)
            {
                printf("Вы ввели неправельный формат даты. Введите, пожалуйста, еще раз.\n");
                scanf_s("%d", &(list + i)->bd.month);
            }
        }
        printf("Год: ");
        scanf("%d", &(list + i)->bd.year);
        if (((list + i)->bd.year > 2020) || ((list + i)->bd.year < 1900))
        {
            while (((list + i)->bd.year > 2020) || ((list + i)->bd.year < 1900))
            {
                printf("Вы ввели неправельный формат даты. Введите, пожалуйста, еще раз.\n");
                scanf("%d", &(list + i)->bd.year);
            }
        }
        printf("\nВы ввели : %s %s, дата рождения %d %d %d года\n",
            (list + i)->firstname, (list + i)->lastname, (list + i)->bd.date, (list + i)->bd.month, (list + i)->bd.year);
    }
}

void* output(persone* list, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\n %d. %s %s", i + 1, (list + i)->firstname, (list + i)->lastname);
        printf(" дата рождения: %d %d %d, Person ID: %d %d ", (list + i)->bd.date, (list + i)->bd.month, (list + i)->bd.year, (list + i)->id.seria, (list + i)->id.nomer);
    }
}

persone* toFebruary(persone* list, persone* persone)
{
    struct persone* newPerson;
    newPerson = (struct persone*)malloc(sizeof(struct persone));

    (newPerson)->id.seria = (list)->id.seria;
    (newPerson)->id.nomer = (list)->id.nomer;
    for (int j = 0; j < 20; j++)
    {
        (newPerson)->firstname[j] = (list)->firstname[j];
        (newPerson)->lastname[j] = (list)->lastname[j];
    }
    (newPerson)->bd.date = 2;
    (newPerson)->bd.month = (list)->bd.month;
    (newPerson)->bd.year = (list)->bd.year;

    printf("\n %s %s", (newPerson)->firstname, (newPerson)->lastname);
    printf(" дата рождения: %d %d %d, Person ID: %d %d ", (newPerson)->bd.date, (newPerson)->bd.month, (newPerson)->bd.year, (newPerson)->id.seria, (newPerson)->id.nomer);

    return newPerson;
}

persone* map(persone* list, int n, persone* (*f)(persone*))
{
    struct persone* lst1;
    lst1 = (struct persone*)malloc(n*sizeof(struct persone));

    for (int i = 0; i < n; i++)
    {
        f(list + i, lst1 + i);
    }
    return lst1;
}

bool* AfterMay(persone* list, persone* persone)
{
    struct persone* newPerson;
    newPerson = (struct persone*)malloc(sizeof(struct persone));

    if (((list)->bd.month) > 5)
    {
        (newPerson)->id.seria = (list)->id.seria;
        (newPerson)->id.nomer = (list)->id.nomer;
        for (int j = 0; j < 20; j++)
        {
            (newPerson)->firstname[j] = (list)->firstname[j];
            (newPerson)->lastname[j] = (list)->lastname[j];
        }
        (newPerson)->bd.date = (list)->bd.date;
        (newPerson)->bd.month = (list)->bd.month;
        (newPerson)->bd.year = (list)->bd.year;

        printf("\n %s %s", (newPerson)->firstname, (newPerson)->lastname);
        printf(" дата рождения: %d %d %d, Person ID: %d %d ", (newPerson)->bd.date, (newPerson)->bd.month, (newPerson)->bd.year, (newPerson)->id.seria, (newPerson)->id.nomer);
       
        return true;
    }

    else return false;

}

void* where(persone* list, int n, bool* (*m)(persone*))
{
    struct persone* lst2;
    lst2 = (struct persone*)malloc(n * sizeof(struct persone));

    for (int i = 0; i < n; i++)
    {
        m(list + i, lst2 + i);
    }
}

void* concat(persone* list, int n)
{
    int i, k;
    struct persone* lst2;

    printf("Заполните новый список. \n Введите кол-во студентов: ");
    scanf("%d", &k);
    lst2 = (struct persone*)malloc(k * sizeof(struct persone)); // Выделение памяти

    printf("Введите данные:");
    input(lst2, k);
    printf("Вы ввели:");
    output(lst2, k);
    printf("\nОбъединим 1 и 2 списки:");

    struct persone* lst1;
    lst1 = (struct persone*)malloc((n + k) * sizeof(struct persone));
    for (i = 0; i < n; i++)
    {
        (lst1 + i)->id.seria = (list + i)->id.seria;
        (lst1 + i)->id.nomer = (list + i)->id.nomer;
        for (int j = 0; j < 20; j++)
        {
            (lst1 + i)->firstname[j] = (list + i)->firstname[j];
            (lst1 + i)->lastname[j] = (list + i)->lastname[j];
        }
        (lst1 + i)->bd.date = (list + i)->bd.date;
        (lst1 + i)->bd.month = (list + i)->bd.month;
        (lst1 + i)->bd.year = (list + i)->bd.year;
    }

    for (i = n; i < (n + k); i++)
    {
        (lst1 + i)->id.seria = (lst2 + i - n)->id.seria;
        (lst1 + i)->id.nomer = (lst2 + i - n)->id.nomer;
        for (int j = 0; j < 20; j++)
        {
            (lst1 + i)->firstname[j] = (lst2 + i - n)->firstname[j];
            (lst1 + i)->lastname[j] = (lst2 + i - n)->lastname[j];
        }
        (lst1 + i)->bd.date = (lst2 + i - n)->bd.date;
        (lst1 + i)->bd.month = (lst2 + i - n)->bd.month;
        (lst1 + i)->bd.year = (lst2 + i - n)->bd.year;
    }

    output(lst1, (n + k));

}


persone* FuncApril(persone* list, persone* persone)
{
    struct persone* newPerson;
    newPerson = (struct persone*)malloc( sizeof(struct persone));

    int count = 1;
    char z;
    z = 'z';

        for (int j = 0; (list)->lastname[j] != '\0'; j++)
        {
            if (((list)->lastname[j]) == z)
            {
                count++;
            }
        }

        if (count > 1)
        {
            (newPerson)->id.seria = (list)->id.seria;
            (newPerson)->id.nomer = (list)->id.nomer;
            for (int j = 0; j < 20; j++)
            {
                (newPerson)->firstname[j] = (list)->firstname[j];
                (newPerson)->lastname[j] = (list)->lastname[j];
            }
            (newPerson)->bd.date = 1;
            (newPerson)->bd.month = 4;
            (newPerson)->bd.year = (list)->bd.year;

            printf("\n %s %s", (newPerson)->firstname, (newPerson)->lastname);
            printf(" дата рождения: %d %d %d, Person ID: %d %d ", (newPerson)->bd.date, (newPerson)->bd.month, (newPerson)->bd.year, (newPerson)->id.seria, (newPerson)->id.nomer);
        }
        else
        {
            (newPerson)->id.seria = (list)->id.seria;
            (newPerson)->id.nomer = (list)->id.nomer;
            for (int j = 0; j < 20; j++)
            {
                (newPerson)->firstname[j] = (list)->firstname[j];
                (newPerson)->lastname[j] = (list)->lastname[j];
            }
            (newPerson)->bd.date = (list)->bd.date;
            (newPerson)->bd.month = (list)->bd.month;
            (newPerson)->bd.year = (list)->bd.year;

            printf("\n %s %s", (newPerson)->firstname, (newPerson)->lastname);
            printf(" дата рождения: %d %d %d, Person ID: %d %d ", (newPerson)->bd.date, (newPerson)->bd.month, (newPerson)->bd.year, (newPerson)->id.seria, (newPerson)->id.nomer);
        }
        return newPerson;
}

bool* FuncAprilForWhere(persone* list, persone* persone)
{
    struct persone* newPerson;
    newPerson = (struct persone*)malloc(sizeof(struct persone));

    int count = 1;
    char z;
    z = 'z';

    for (int j = 0; (list)->lastname[j] != '\0'; j++)
    {
        if (((list)->lastname[j]) == z)
        {
            count++;
        }
    }

    if (count > 1)
    {
        (newPerson)->id.seria = (list)->id.seria;
        (newPerson)->id.nomer = (list)->id.nomer;
        for (int j = 0; j < 20; j++)
        {
            (newPerson)->firstname[j] = (list)->firstname[j];
            (newPerson)->lastname[j] = (list)->lastname[j];
        }
        (newPerson)->bd.date = (list)->bd.date;
        (newPerson)->bd.month = (list)->bd.month;
        (newPerson)->bd.year = (list)->bd.year;

        printf("\n %s %s", (newPerson)->firstname, (newPerson)->lastname);
        printf(" дата рождения: %d %d %d, Person ID: %d %d ", (newPerson)->bd.date, (newPerson)->bd.month, (newPerson)->bd.year, (newPerson)->id.seria, (newPerson)->id.nomer);
        return true;
    }

    else return false;


}