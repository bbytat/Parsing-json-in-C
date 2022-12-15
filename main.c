#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>

int main(int argc, char ** argv)
{
    FILE *fp;
    char buffer[2000];

    struct json_object *parsed_json;
    struct json_object *data;

    size_t n_data;
    size_t i;

    fp = fopen("assesment.json", "r");
    fread(buffer, 2000, 1, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(buffer);
    json_object_get_ex(parsed_json, "data", &data);

    n_data = json_object_array_length(data);
    printf("found %lu data\n", n_data);

    for (i=0; i<n_data; i++)
    {
        data = json_object_array_get_idx(data, i);
        printf("%lu. %s\n", i+1, json_object_get_string(data));
    }
}
    









