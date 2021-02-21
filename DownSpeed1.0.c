#define KILO 1000
#define MEGA 1000000
#define GIGA 1000000000
#define TERA 1000000000000
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	float downloadSpeed;
	char speedType;
	float downloadSize;
	char downloadType;
	float downloadSpeedByte;
	float downloadSizeByte;
	unsigned long long downloadTimeSeconds;
	unsigned long long downloadTimeMinutes;
	unsigned long long downloadTimeHours;
	unsigned long long downloadTimeRemainingSeconds;
    	if(argc == 1){
		printf("Enter download speed per second: ");
		scanf("%f", &downloadSpeed);
		getchar();
		printf("Enter speed type (b/k/m/g/t bits): ");
		speedType = getchar();
		printf("Enter file size: ");
		scanf("%f", &downloadSize);
		getchar();
		printf("Enter download type (b/k/m/g/t bytes): ");
		downloadType = getchar();
	}
	else if (argc < 5 && argc > 1 || argc > 5){
        	printf("%s: Invalid Syntax\n Usage: %s [SPEED IN BITS PER SECONDS] [SPEED TYPE] [DOWNLOAD SIZE IN BYTES] [DOWNLOAD TYPE]\n Types: b (Byte) k (Kilo) m (Mega) g (Giga) t (Tera) \n", argv[0],  argv[0]);
        	return(0);
	}
	else{
		downloadSpeed = strtof(argv[1], NULL);
		speedType = *argv[2];
		downloadSize = strtof(argv[3], NULL);
		downloadType = *argv[4];

	}

	switch (speedType){
		case 'b':
			downloadSpeedByte = (downloadSpeed/8);
			break;
		case 'k':
		       	downloadSpeedByte = (downloadSpeed/8)*KILO;
			break;
		case 'm':
			downloadSpeedByte = (downloadSpeed/8)*MEGA;
			break;
		case 'g':
			downloadSpeedByte = (downloadSpeed/8)*GIGA;
			break;
		case 't':
			downloadSpeedByte = (downloadSpeed/8)*TERA;
			break;
		default:
			printf("That is not valid input, Please try again.\n");
			return (-1);
			break;
	}
	switch (downloadType){
		case 'b':
			downloadSizeByte = (downloadSize);
			break;
		case 'k':
		       	downloadSizeByte = (downloadSize)*KILO;
			break;
		case 'm':
			downloadSizeByte = (downloadSize)*MEGA;
			break;
		case 'g':
			downloadSizeByte = (downloadSize)*GIGA;
			break;
		case 't':
			downloadSizeByte = (downloadSize)*TERA;
			break;
		default:
			printf("That is not valid input, Please try again.\n");
			return (-1);
			break;
	}
	downloadTimeSeconds = (downloadSizeByte)/(downloadSpeedByte);
	downloadTimeHours = (downloadTimeSeconds/(60*60));
	downloadTimeRemainingSeconds = downloadTimeSeconds - (downloadTimeHours * (60*60));
	downloadTimeMinutes = downloadTimeRemainingSeconds/60;
	downloadTimeRemainingSeconds = downloadTimeRemainingSeconds - (downloadTimeMinutes*60);
	printf("It will take %llu Hours, %llu Minutes, %llu Seconds to download.\n", downloadTimeHours,downloadTimeMinutes,downloadTimeRemainingSeconds);
	return 0;
}
