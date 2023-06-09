#include "hash_tables.h"

/**

 * hash_table_get - function to retrieve value associeted with key

 * @ht: pointer to hash table

 * @key: key to retrive value

 *

 * Return: value or NULL if key does not exit.

 */


char *hash_table_get(const hash_table_t *ht, const char *key)

{

        unsigned long int index = 0;

        hash_node_t  *bucket;


        if (!ht || !key || !*key)

                return (NULL);


        index = key_index((const unsigned char *)key, ht->size);

        bucket = ht->array[index];


        while (bucket)

        {

                if (!strcmp(key, bucket->key))

                        return (bucket->value);

                bucket = bucket->next;

        }

        return (NULL);

}



________________________________




4-main.c



#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include "hash_tables.h"


/**

 * main - check the code

 *

 * Return: Always EXIT_SUCCESS.

 */

int main(void)

{

    hash_table_t *ht;

    char *value;


    ht = hash_table_create(1024);

    hash_table_set(ht, "c", "fun");

    hash_table_set(ht, "python", "awesome");

    hash_table_set(ht, "Bob", "and Kris love asm");

    hash_table_set(ht, "N", "queens");

    hash_table_set(ht, "Asterix", "Obelix");

    hash_table_set(ht, "Betty", "Cool");

    hash_table_set(ht, "98", "Battery Street");

    hash_table_set(ht, "c", "isfun");


    value = hash_table_get(ht, "python");

    printf("%s:%s\n", "python", value);

    value = hash_table_get(ht, "Bob");

    printf("%s:%s\n", "Bob", value);

    value = hash_table_get(ht, "N");

    printf("%s:%s\n", "N", value);

    value = hash_table_get(ht, "Asterix");

    printf("%s:%s\n", "Asterix", value);

    value = hash_table_get(ht, "Betty");

    printf("%s:%s\n", "Betty", value);

    value = hash_table_get(ht, "98");

    printf("%s:%s\n", "98", value);

    value = hash_table_get(ht, "c");

    printf("%s:%s\n", "c", value);

    value = hash_table_get(ht, "javascript");

    printf("%s:%s\n", "javascript", value);

    return (EXIT_SUCCESS);

}



________________________________




5-hash_table_print.c



#include "hash_tables.h"


/**

 * hash_table_print - function to print the key:value from ht

 * @ht: pointer to hash table

 *

 */

void hash_table_print(const hash_table_t *ht)

{

        unsigned long int i = 0;

        hash_node_t  *bucket;

        int not_fin = 0;


        if (!ht)

                return;


        printf("{");

        for (i = 0; i < ht->size; i++)

        {

                bucket = ht->array[i];

                while (bucket)

                {

                        if (not_fin)

                                printf(", ");

                        printf("'%s': '%s'", bucket->key, bucket->value);

                        not_fin = 1;

                        bucket = bucket->next;

                }

        }

        printf("}\n");

}

