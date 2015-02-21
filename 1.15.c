#include <glib/gstdio.h>
#include <locale.h>
#include <libsmartcols/libsmartcols.h>

float
fahr_to_celsius (float fahr)
{
  return ((5.0 / 9.0) * (fahr - 32.0));
}

int
main (int argc, char *argv[])
{
  struct libscols_table *tb;
  struct libscols_line *ln;
  enum {
    FAHRENHEIT, CELSIUS
  };

  setlocale (LC_ALL, "");

  gfloat fahr, celsius;
  gint lower, upper, step;
  gchar *s;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  tb = scols_new_table ();
  scols_table_new_column (tb, "FAHRENHEIT", 0.5, 0);
  scols_table_new_column (tb, "CELSIUS", 0.5, 0);
  while (fahr <= upper) {
    ln = scols_table_new_line (tb, NULL);
    s = g_strdup_printf ("%.0f", fahr);
    scols_line_set_data (ln, FAHRENHEIT, s);
    celsius = fahr_to_celsius (fahr);
    s = g_strdup_printf ("%.1f", celsius);
    scols_line_set_data (ln, CELSIUS, s);
    fahr += step;
  }
  g_printf ("\n");
  scols_print_table (tb);
  scols_unref_table (tb);

  return 0;
}
