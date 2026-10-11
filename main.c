#include"header.h"
int main()
{
	int id=semget(3,5,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return 1;
	}
	perror("semget");
	semctl(id,0,SETVAL,1);
	printf("fork1 is available\n");
	semctl(id,1,SETVAL,1);
	printf("fork2 is available\n");
	semctl(id,2,SETVAL,1);
	printf("fork3 is available\n");
	semctl(id,3,SETVAL,1);
	printf("fork4 is available\n");
	semctl(id,4,SETVAL,1);
	printf("fork5 is available\n");
	int pid1,pid2,pid3,pid4,pid5;
	struct sembuf v;
	if((pid1=fork())==0)
	{
			printf("In child1,pid=%d\n",getpid());
			printf("P1 is thinking\n");
			sleep(3);
			printf("P1 is hungry\n");
			v.sem_num=0;
			v.sem_op=-1;
			v.sem_flg=0;
			semop(id,&v,1);
			v.sem_num=4;
			v.sem_op=-1;
			v.sem_flg=0;
			semop(id,&v,1);
			printf("P1 is eating f1 and f5\n");
			v.sem_num=4;
			v.sem_op=1;
			v.sem_flg=0;
			semop(id,&v,1);
			v.sem_num=0;
			v.sem_op=1;
			v.sem_flg=0;
			semop(id,&v,1);
			printf("P1 released f1 and f5\n");
		exit(0);
		}
		else
		{
			if((pid2=fork())==0)
			{
				printf("In child2,pid=%d\n",getpid());
					printf("P2 is thinking\n");
					sleep(3);
					printf("P2 is hungry\n");
					v.sem_num=0;
					v.sem_op=-1;
					v.sem_flg=0;
					semop(id,&v,1);
					v.sem_num=1;
					v.sem_op=-1;
					v.sem_flg=0;
					semop(id,&v,1);
					printf("P2 is eating f1 and f2\n");
					v.sem_num=1;
					v.sem_op=1;
					v.sem_flg=0;
					semop(id,&v,1);
					v.sem_num=0;
					v.sem_op=1;
					v.sem_flg=0;
					semop(id,&v,1);
					printf("P2 released f1 and f2\n");
				exit(0);
				}
				else
				{
					if((pid3=fork())==0)
					{
						printf("In child3,pid=%d\n",getpid());
							printf("P3 is thinking\n");
							sleep(3);
							printf("P3 is hungry\n");
							v.sem_num=2;
							v.sem_op=-1;
							v.sem_flg=0;
							semop(id,&v,1);
							v.sem_num=1;
							v.sem_op=-1;
							v.sem_flg=0;
							semop(id,&v,1);
							printf("P3 is eating f3 and f2\n");
							v.sem_num=1;
							v.sem_op=1;
							v.sem_flg=0;
							semop(id,&v,1);
							v.sem_num=2;
							v.sem_op=1;
							v.sem_flg=0;
							semop(id,&v,1);
							printf("P3 released f3 and f2\n");
						exit(0);
						}
						else
						{
							if((pid4=fork())==0)
							{
								printf("In child4,pid=%d\n",getpid());
									printf("P4 is thinking\n");
									sleep(3);
									printf("P4 is hungry\n");
									v.sem_num=2;
									v.sem_op=-1;
									v.sem_flg=0;
									semop(id,&v,1);
									v.sem_num=3;
									v.sem_op=-1;
									v.sem_flg=0;
									semop(id,&v,1);
									printf("P4 is eating f3 and f4\n");
									v.sem_num=3;
									v.sem_op=1;
									v.sem_flg=0;
									semop(id,&v,1);
									v.sem_num=2;
									v.sem_op=1;
									v.sem_flg=0;
									semop(id,&v,1);
									printf("P4 released f3 and f4\n");
								exit(0);
								}
								else
								{
									if((pid5=fork())==0)
									{
										printf("In child5,pid=%d\n",getpid());
											printf("P5 is thinking\n");
											sleep(3);
											printf("P5 is hungry\n");
											v.sem_num=4;
											v.sem_op=-1;
											v.sem_flg=0;
											semop(id,&v,1);
											v.sem_num=3;
											v.sem_op=-1;
											v.sem_flg=0;
											semop(id,&v,1);
											printf("P5 is eating f5 and f4\n");
											v.sem_num=3;
											v.sem_op=1;
											v.sem_flg=0;
											semop(id,&v,1);
											v.sem_num=4;
											v.sem_op=1;
											v.sem_flg=0;
											semop(id,&v,1);
											printf("P5 released f5 and f4\n");
										exit(0);
										}
										else
										{
											printf("In parent,pid=%d\n",getpid());
											wait(0);
											wait(0);
											wait(0);
											wait(0);
											wait(0);
											semctl(id,0,IPC_RMID);
											printf("All semphores are deleted\n");
										}
									}

								}
							}
						}
					}


