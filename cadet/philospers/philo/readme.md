

### 07.24(sun)

**문제점**

1. is thinking, is sleeping이 출력되지 않는다.
2. died가 정상적으로 출력되지 않는다.



### 07.25(mon)
**문제점**
1. die 이후 출력을 mutex로 locking
2. data race 해결하기. 
**해결**

1. died가 제대로 찍히지 않는 문제 해결.

```c

void	check_death(t_info *info, t_philo *philo)
{
	int			i;
	long long	now;	

	while (info->death == 0)
	{
		if ((info->time_to_eat != 0) && (info->cnt_of_philo == info->finish_to_eat))
		{
			info->death = 1;
		}
		// 여기 있는 i를 맨 위에서 초기화 해서 맨 처음 식사횟수만 체크를 했음. 
		그러나 이제. 한 턴마다 ㅏ계속 체크를 해줌
		i = 0;
		while (i < info->cnt_of_philo)
		{
			now = get_time();
			if ((now - philo[i].last_food_time) >= info->time_to_die)
			{
				print_state(info, "died", i);
				info->death = 1;
			}
			i++;
		}
	}
}
```

```c
./philo 4 410 200 200 7 > test.txt
cat test.txt | grep "1 is e" | wc -l
cat test.txt | grep "2 is e" | wc -l
cat test.txt | grep "3 is e" | wc -l
cat test.txt | grep "4 is e" | wc -l
```
