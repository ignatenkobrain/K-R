#include <glib/gstdio.h>
#include <locale.h>
#include <libsmartcols/libsmartcols.h>

#define SYMBOLS 256

int
main(int argc, char *argv[])
{
  gint c;
  guint i;
  gchar *s;
  gint arr[SYMBOLS] = { 0 };

  struct libscols_table *tb;
  struct libscols_line *ln;
  struct libscols_column *cl;
  enum {
    COL_SYM, COL_CHART
  };

  setlocale(LC_ALL, "");

  while ((c = getchar()) != EOF)
    arr[c]++;

  tb = scols_new_table();
  scols_table_new_column(tb, "SYM", 0.1, 0);
  scols_table_new_column(tb, "BAR CHART", 0.9, 0);
  for (c = 0; c < SYMBOLS; c++)
    if (arr[c] != 0) {
      ln = scols_table_new_line(tb, NULL);
      s = g_strescape(g_strdup_printf("'%c'", c), NULL);
      scols_line_set_data(ln, COL_SYM, s);
      s = g_strdup("");
      for (i = 0; i < arr[c]; i++)
        s = g_strconcat(s, "-", NULL);
      s = g_strdup_printf("%s>", s);
      scols_line_set_data(ln, COL_CHART, s);
    }
  g_printf("\n");
  cl = scols_table_get_column(tb, COL_SYM);
  scols_column_set_cmpfunc(cl, scols_cmpstr_cells, NULL);
  scols_sort_table(tb, cl);
  scols_print_table(tb);
  scols_unref_table(tb);

	return (0);
}

