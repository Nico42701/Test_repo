/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include <unistd.h>
#include "my.h"

int count_occurrences(const char *str, const char *old)
{
    int count = 0;
    int old_len = my_strlen(old);
    const char *tmp = str;

    if (!str || !old || old_len == 0)
        return 0;
    tmp = my_strstr(tmp, old);
    while (tmp) {
        count++;
        tmp += old_len;
        tmp = my_strstr(tmp, old);
    }
    return count;
}

int calculate_new_size(const char *str, const char *old, const char *new_str)
{
    int count = count_occurrences(str, old);
    int old_len = my_strlen(old);
    int new_len = my_strlen(new_str);
    int str_len = my_strlen(str);

    return str_len + count * (new_len - old_len) + 1;
}

void replace_occurrence_ctx(replace_ctx_t *ctx)
{
    int n = ctx->tmp - ctx->cur;
    int new_len = my_strlen(ctx->new_str);

    my_memcpy(*(ctx->res_ptr), ctx->cur, n);
    *(ctx->res_ptr) += n;
    my_memcpy(*(ctx->res_ptr), ctx->new_str, new_len);
    *(ctx->res_ptr) += new_len;
}

void process_replacements(char *result, const char *str,
    const char *old, const char *new_str)
{
    char *res_ptr = result;
    const char *cur = str;
    const char *tmp = my_strstr(cur, old);
    replace_ctx_t ctx = {0};

    while (tmp) {
        ctx.res_ptr = &res_ptr;
        ctx.cur = cur;
        ctx.tmp = tmp;
        ctx.old = old;
        ctx.new_str = new_str;
        replace_occurrence_ctx(&ctx);
        cur = tmp + my_strlen(old);
        tmp = my_strstr(cur, old);
    }
    my_strcpy(res_ptr, cur);
}

char *my_str_replace(const char *str, const char *old, const char *new_str)
{
    char *result = NULL;
    int new_size = 0;

    if (!str || !old || !new_str)
        return NULL;
    new_size = calculate_new_size(str, old, new_str);
    result = malloc(new_size);
    if (!result)
        return NULL;
    process_replacements(result, str, old, new_str);
    return result;
}
