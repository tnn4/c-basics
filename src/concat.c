char* concat(const char *s1, const char *s1){
    char *result;

    result = malloc(strlen(s1)+strlen(s2)+1);
    if ( result == NULL ){
        printf("[Error]: malloc failed in concat\n");
        exit(EXIT_FAILURE);
    }
    strcpy(result, s1);
    strcpy(result, s2);
    return result;
}
