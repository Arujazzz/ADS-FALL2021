#include <bits/stdc++.h>
using namespace std;


//Инициализация ОЛС
struct list * init(int a) // а- значение первого узла
{
  struct list *lst;
  // выделение памяти под корень списка
  lst = (struct list*)malloc(sizeof(struct list));
  lst->field = a;
  lst->ptr = NULL; // это последний узел списка
  return(lst);
}

//Добавление узла в ОЛС
struct list * addelem(list *lst, int number)
{
  struct list *temp, *p;
  temp = (struct list*)malloc(sizeof(list));
  p = lst->ptr; // сохранение указателя на следующий узел
  lst->ptr = temp; // предыдущий узел указывает на создаваемый
  temp->field = number; // сохранение поля данных добавляемого узла
  temp->ptr = p; // созданный узел указывает на следующий элемент
  return(temp);
}

//Удаление узла ОЛС
struct list * deletelem(list *lst, list *root)
{
  struct list *temp;
  temp = root;
  while (temp->ptr != lst) // просматриваем список начиная с корня
  { // пока не найдем узел, предшествующий lst
    temp = temp->ptr;
  }
  temp->ptr = lst->ptr; // переставляем указатель
  free(lst); // освобождаем память удаляемого узла
  return(temp);
}

//Удаление корня списка
struct list * deletehead(list *root)
{
  struct list *temp;
  temp = root->ptr;
  free(root); // освобождение памяти текущего корня
  return(temp); // новый корень списка
}

//Вывод элементов списка
void listprint(list *lst)
{
  struct list *p;
  p = lst;
  do {
    printf("%d ", p->field); // вывод значения элемента p
    p = p->ptr; // переход к следующему узлу
  } while (p != NULL);
}

//Взаимообмен узлов ОЛС
struct list * swap(struct list *lst1, struct list *lst2, struct list *head)
{
  // Возвращает новый корень списка
  struct list *prev1, *prev2, *next1, *next2;
  prev1 = head;
  prev2 = head;
  if (prev1 == lst1)
    prev1 = NULL;
  else
    while (prev1->ptr != lst1) // поиск узла предшествующего lst1
      prev1 = prev1->ptr;
  if (prev2 == lst2)
    prev2 = NULL;
  else
    while (prev2->ptr != lst2) // поиск узла предшествующего lst2
      prev2 = prev2->ptr;
  next1 = lst1->ptr;  // узел следующий за lst1
  next2 = lst2->ptr;  // узел следующий за lst2
  if (lst2 == next1)
  {                       // обмениваются соседние узлы
    lst2->ptr = lst1;
    lst1->ptr = next2;
    if (lst1 != head)
      prev1->ptr = lst2;
  }
  else
    if (lst1 == next2)
    {
      // обмениваются соседние узлы
      lst1->ptr = lst2;
      lst2->ptr = next1;
      if (lst2 != head)
        prev2->ptr = lst2;
    }
    else
    {
      // обмениваются отстоящие узлы
      if (lst1 != head)
        prev1->ptr = lst2;
      lst2->ptr = next1;
      if (lst2 != head)
        prev2->ptr = lst1;
      lst1->ptr = next2;
    }
  if (lst1 == head)
    return(lst2);
  if (lst2 == head)
    return(lst1);
  return(head);
}

int main(){

    return 0;
}
