#!/bin/bash
while :
do
    sleep 2
    leaks philo > leaks_result; cat leaks_result | grep leaked; rm -rf leaks_result
done