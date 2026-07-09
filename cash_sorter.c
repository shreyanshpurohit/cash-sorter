#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

GtkWidget *entry;
GtkWidget *quarter_label;
GtkWidget *dime_label;
GtkWidget *nickel_label;
GtkWidget *penny_label;
GtkWidget *total_label;

int calculate_quarter(int cents)
{
    int quarters = 0;
    while (cents >=25)
    {
        cents -= 25;
        quarters++;
    }
    return quarters;
}

int calculate_dime(int cents)
{
    int dimes = 0;
    while (cents >=10)
    {
        cents -= 10;
        dimes++;
    }
    return dimes;
}

int calculate_nickel(int cents)
{
    int nickels = 0;
    while (cents >=5)
    {
        cents -= 5;
        nickels++;
    }
    return nickels;
}

static void calculate(GtkButton *button, gpointer data)
{
    const char *text = gtk_editable_get_text(GTK_EDITABLE(entry));

    char *endptr;
    long cents = strtol(text, &endptr, 10);

    if (*text == '\0' || *endptr != '\0' || cents < 0)
    {
        gtk_label_set_text(GTK_LABEL(total_label), "Please enter a valid number.");
        gtk_label_set_text(GTK_LABEL(quarter_label), "");
        gtk_label_set_text(GTK_LABEL(dime_label), "");
        gtk_label_set_text(GTK_LABEL(nickel_label), "");
        gtk_label_set_text(GTK_LABEL(penny_label), "");
        return;
    }

    int quarters = calculate_quarter(cents);
    cents -= quarters * 25;

    int dimes = calculate_dime(cents);
    cents -= dimes * 10;

    int nickels = calculate_nickel(cents);
    cents -= nickels * 5;

    int pennies = cents;
    int total = quarters + dimes + nickels + pennies;

    char buffer[100];

    sprintf(buffer, "Quarters: %d", quarters);
    gtk_label_set_text(GTK_LABEL(quarter_label), buffer);

    sprintf(buffer, "Dimes: %d", dimes);
    gtk_label_set_text(GTK_LABEL(dime_label), buffer);

    sprintf(buffer, "Nickels: %d", nickels);
    gtk_label_set_text(GTK_LABEL(nickel_label), buffer);

    sprintf(buffer, "Pennies: %d", pennies);
    gtk_label_set_text(GTK_LABEL(penny_label), buffer);

    sprintf(buffer, "Total Coins: %d", total);
    gtk_label_set_text(GTK_LABEL(total_label), buffer);
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *button;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Cash Sorter");
    gtk_window_set_default_size(GTK_WINDOW(window), 350, 300);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_margin_top(box, 15);
    gtk_widget_set_margin_bottom(box, 15);
    gtk_widget_set_margin_start(box, 15);
    gtk_widget_set_margin_end(box, 15);

    gtk_window_set_child(GTK_WINDOW(window), box);

    GtkWidget *label = gtk_label_new("Enter Change Owed (¢)");
    gtk_box_append(GTK_BOX(box), label);

    entry = gtk_entry_new();
    gtk_box_append(GTK_BOX(box), entry);

    button = gtk_button_new_with_label("Calculate");
    g_signal_connect(button, "clicked", G_CALLBACK(calculate), NULL);
    gtk_box_append(GTK_BOX(box), button);

    quarter_label = gtk_label_new("");
    dime_label = gtk_label_new("");
    nickel_label = gtk_label_new("");
    penny_label = gtk_label_new("");
    total_label = gtk_label_new("");

    gtk_box_append(GTK_BOX(box), quarter_label);
    gtk_box_append(GTK_BOX(box), dime_label);
    gtk_box_append(GTK_BOX(box), nickel_label);
    gtk_box_append(GTK_BOX(box), penny_label);
    gtk_box_append(GTK_BOX(box), total_label);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.cashsorter", G_APPLICATION_DEFAULT_FLAGS);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);
    return status;
}
