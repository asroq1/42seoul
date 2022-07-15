/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:42:24 by hyunjung          #+#    #+#             */
/*   Updated: 2022/07/15 16:25:33 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int g_num = 0;
int lock = 0;
pthread_mutex_t *mutex;

void *nomutex()
{
    for (int i = 0; i < 10000; i++) {
        g_num++;
    }
    return (0);
}

void *ft_test_2()
{
    for (int i = 0; i < 10000; i++) {
        while(lock == 1)
            ;
        lock = 1;
        g_num++;
        lock = 0;
    }
    return (0);
}

void *ft_test()
{
    printf("thread created...\n");
    mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(mutex, NULL);
    for (int i = 0; i < 10000; i++) {
        // usleep(50);
        pthread_mutex_lock(mutex);
        //printf("locked\n");
        g_num++;
        pthread_mutex_unlock(mutex);
        //printf("unlocked\n");
    }
    return (0);
}

int main(void)
{
    int i = 0;
    pthread_t tid;

    while (i < 2)
    {
        pthread_create(&tid, NULL, ft_test, NULL);
        printf("tid => %d\n", tid);
        i++;
    }
    i = 0;
    while (i < 2)
    {
        pthread_join(tid, NULL);
        i++;
    }
    printf("%d\n", g_num);
    return (0);
}