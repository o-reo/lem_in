/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:37:17 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 15:23:46 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <check.h>
#include "lem_in.h"

START_TEST (libft)
{
    fail_unless(ft_strsplit("plop plip", ' '), "this should succeed");
}
END_TEST

int main(void)
{
	int nf;

	Suite *s1 = suite_create("Lem_in");
	TCase *tc1_1 = tcase_create("Lem_in");
	SRunner *sr = srunner_create(s1);
	suite_add_tcase(s1, tc1_1);
	tcase_add_test(tc1_1, libft);
	srunner_run_all(sr, CK_VERBOSE);
	nf = srunner_ntests_failed(sr);
	srunner_free(sr);
	return nf == 0 ? 0 : 1;
}
