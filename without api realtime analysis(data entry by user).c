#include <stdio.h>

struct weather {
    char date[15];
    float temperature;
    float humidity;
    float pressure;
};

void addWeather(struct weather *weathers, int *count);
void displayWeather(struct weather *weathers, int count);
void searchWeather(struct weather *weathers, int count, char *date);

int main() {
    struct weather weathers[100];
    int count = 0;
    int choice;
    char date[15];

    do {
        printf("\n1. Add Weather\n");
        printf("2. Display Weather\n");
        printf("3. Search Weather\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addWeather(weathers, &count);
                break;
            case 2:
                displayWeather(weathers, count);
                break;
            case 3:
                printf("Enter date to search (DD/MM/YYYY): ");
                scanf("%s", date);
                searchWeather(weathers, count, date);
                break;
            case 4:
                return 0;
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(1);

    return 0;
}

void addWeather(struct weather *weathers, int *count) {
    struct weather newWeather;

    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", newWeather.date);

    printf("Enter temperature: ");
    scanf("%f", &newWeather.temperature);

    printf("Enter humidity: ");
    scanf("%f", &newWeather.humidity);

    printf("Enter pressure: ");
    scanf("%f", &newWeather.pressure);

    weathers[*count] = newWeather;
    (*count)++;

    printf("Weather added successfully.\n");
}

void displayWeather(struct weather *weathers, int count) {
    if(count == 0) {
        printf("No weather data to display.\n");
    } else {
        printf("Date\tTemperature\tHumidity\tPressure\n");

        for (; count > 0; count--) {
            printf("%s\t%.2f\t\t%.2f\t\t%.2f\n", weathers[count - 1].date, weathers[count - 1].temperature, weathers[count - 1].humidity, weathers[count - 1].pressure);
        }
    }
}

void searchWeather(struct weather *weathers, int count, char *date) {
    for (; count > 0; count--) {
        if(strcmp(weathers[count - 1].date, date) == 0) {
            printf("Date: %s\n", weathers[count - 1].date);
            printf("Temperature: %.2f\n", weathers[count - 1].temperature);
            printf("Humidity: %.2f\n", weathers[count - 1].humidity);
            printf("Pressure: %.2f\n", weathers[count - 1].pressure);
            return;
        }
    }

    printf("Weather data for %s not found.\n", date);
}
