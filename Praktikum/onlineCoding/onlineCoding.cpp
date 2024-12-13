#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

#define gc getchar();

struct datTeam {
	char id[100];
	char name[100];
	char idea[100];
	char event[100];
};

struct datEvent {
	char name[100];
	int total;
};

datTeam team[1000];
int countTeam = 0;

datEvent event[1000];
int countEvent = 0;

void swap();
int partition();
void sort();

void loadEvent();
void loadTeam();

void saveEvent();
void saveTeam();

void printMenu();
void enterToContinue();

void create();
void view();
void del();

int main() {
	do {
		srand(time(0));
		printMenu();
		
		int input = -1;
		do {
			printf(">> ");
			scanf("%d", &input); gc
		} while (input < 1 || input > 4);
		
		switch (input) {
			case 1 :
				create();
				break;
			case 2 :
				view();
				enterToContinue();
				break;
			case 3 :
				del();
				break;
			case 4 :
				return 0;
		}
	} while (1);
	return 0;
}

void swap(datEvent *a, datEvent *b) {
	datEvent temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int low, int high) {
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (event[j].total > event[high].total) {
			i++;
			swap(&event[j], &event[i]);
		} else if (event[j].total == event[high].total) {
			if (strcmp(event[j].name, event[high].name) > 0) {
			i++;
			swap(&event[j], &event[i]);
			}
		}
	}
	
	swap(&event[i + 1], &event[high]);
	return i + 1;
}

void sort(int low, int high) {
	if (low >= high) return;
	
	int p = partition(low, high);
	sort(low, p - 1);
	sort(p + 1, high);
}

void loadEvent() {
	FILE *f = fopen("files/events.txt", "r");
	
	if (f == NULL) return;
	
	countEvent = 0;
	while (fscanf(f, "%[^|]|%d\n", event[countEvent].name, &event[countEvent].total) != EOF) {
		countEvent++;
	}
	
	fclose(f);
}

void loadTeam() {
	FILE *f = fopen("files/list_team.txt", "r");
	
	if (f == NULL) return;
	
	countTeam = 0;
	while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^\n]\n", team[countTeam].id, team[countTeam].name,
			team[countTeam].idea, team[countTeam].event) != EOF) {
		countTeam++;
	}
	
	fclose(f);
}

void saveEvent() {
	FILE *f = fopen("files/events.txt", "w");
	
	if (f == NULL) return;
	
	for (int i = 0; i < countEvent; i++) {
		fprintf(f, "%s|%d\n", event[i].name, event[i].total);
	}
	
	fclose(f);
}

void saveTeam() {
	FILE *f = fopen("files/list_team.txt", "w");
	
	if (f == NULL) return;
	
	for (int i = 0; i < countTeam; i++) {
		fprintf(f, "%s|%s|%s|%s\n", team[i].id, team[i].name, team[i].idea, team[i].event);
	}
	
	fclose(f);
}

void printMenu() {
	system("cls");
	loadEvent();
	loadTeam();
	puts("Coding Competition");
	puts("==================");
	puts("1. Register Team");
	puts("2. View All Registered Team");
	puts("3. Delete Registered Team");
	puts("4. Exit");
}

void enterToContinue() {
	puts("Press Enter To Continue..."); gc
}

void create() {
	system("cls");
	sort(0, countEvent - 1);
	
	for (int i = 0; i < countEvent; i++) {
		printf("%s | %d\n", event[i].name, event[i].total);
	}
	
	datTeam temp;
	// Event
	int flagEvent = 0;
	do {
		printf("Choose the event above [Case Sensitive] : ");
		scanf("%[^\n]", temp.event); gc
		
		for (int i = 0; i < countEvent; i++) {
			if (strcmp(event[i].name, temp.event) == 0) {
				event[i].total++;
				flagEvent = 1;
				break;
			}
		}
	} while (!flagEvent);
	
	// Name
	do {
		printf("Input team name [Must be more than 5 characters] : ");
		scanf("%[^\n]", temp.name); gc
	} while (strlen(temp.name) <= 5);
	
	// Idea
	int countSpace = 0;
	do {
		printf("Input team idea [Must be atleast contain 2 words] : ");
		scanf("%[^\n]", temp.idea); gc
		
		int l = strlen(temp.idea);
		for (int i = 0; i <= l; i++) {
			if (temp.idea[i] == ' ' || temp.idea[i] == '\0' ) countSpace++;
		}
	} while (countSpace < 2);
	
	// ID
	sprintf(temp.id, "TI%d%d%d", rand() % 10, rand() % 10, rand() % 10);
	
	team[countTeam++] = temp;
	saveEvent();
	saveTeam();
	puts("Register Successfully...");
	
	enterToContinue();
}

void view() {
	system("cls");
	if (countTeam == 0) {
		puts("There are no teams registered yet...");
		enterToContinue();
		return;
	}
	
	for (int i = 0; i < countTeam; i++) {
		printf("No. %d\n",  i + 1);
		printf("ID : %s\n", team[i].id);
		printf("Name : %s\n", team[i].name);
		printf("Idea : %s\n", team[i].idea);
		printf("Event : %s\n", team[i].event);
		puts("===================");
	}
	printf("\n");
}

void del() {
	view();
	
	char target[100];
	int flagTarget = 0, idx = -1;
	do {
		printf("Input ID : ");
		scanf("%[^\n]", target); gc
		
		for (int i = 0; i < countTeam; i++) {
			if (strcmp(target, team[i].id) == 0) {
				flagTarget = 1;
				idx = i;
				break;
			}
		}
	} while (!flagTarget);
	
	for (int i = idx; i < countTeam - 1; i++) {
		team[i] = team[i+1];
	}
	countTeam--;
	
	for (int i = 0; i < countEvent; i++) {
		if (strcmp(team[idx].event, event[i].name) == 0) event[i].total--;
	}
	
	saveEvent();
	saveTeam();
	
	puts("Delete Successfully...");
	enterToContinue();
}
