#include "linked_list.h"

/*
=============================================================================

                            EXAMPLE USAGE

=============================================================================
*/

struct person {
    char name[20];
    int age;
};

void print_person(void* data) {
    struct person* person = (struct person*) data;
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int compare_person_ages(const void* a, const void* b) {
    struct person* obj1 = (struct person*)a;
    struct person* obj2 = (struct person*)b;
    return obj1->age < obj2->age;
}

int main() {
    struct linked_list* list = create_linked_list();

    struct person person1;
    strcpy(person1.name, "John");
    person1.age = 25;
    add_node(list, &person1);

    struct person person2;
    strcpy(person2.name, "Alice");
    person2.age = 30;
    add_node(list, &person2);

    struct person person3;
    strcpy(person3.name, "Alice");
    person3.age = 15;
    add_node(list, &person3);

    delete_node(list, &person2);

    quicksort(list, compare_person_ages);

    print_list(list, print_person);

//     struct node* temp = list->head;
//     while (temp != NULL) {
//         struct person* p = (struct person*) temp->data;
//         if (strcmp(p->name, "John") == 0) {
//             printf("FOUND \n");
//         }
//         temp = temp->next;
//     }
    for (struct node* temp = list->head; temp != NULL; temp = temp->next) {
        struct person* p = (struct person*) temp->data;
        if (strcmp(p->name, "John") == 0) {
            printf("FOUND \n");
        }
    }

    return 0;
}

