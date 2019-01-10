/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:37:17 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 14:33:55 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <check.h>
#include "lem_in.h"

START_TEST (rooms)
{
    fail_unless(5 == 5, "this should succeed");
    fail_unless(6 == 6, "this should fail");
}
END_TEST

START_TEST (links)
{
    fail_unless(5 == 5, "this should succeed");
    fail_unless(6 == 6, "this should fail");
}
END_TEST

int main(void)
{
	int nf;

	Suite *s1 = suite_create("Lem_in");
	TCase *tc1_1 = tcase_create("Lem_in");
	SRunner *sr = srunner_create(s1);
	suite_add_tcase(s1, tc1_1);
	tcase_add_test(tc1_1, rooms);
	tcase_add_test(tc1_1, links);
	srunner_run_all(sr, CK_VERBOSE);
	nf = srunner_ntests_failed(sr);
	srunner_free(sr);
	return nf == 0 ? 0 : 1;
}
