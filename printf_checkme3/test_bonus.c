/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <yyuskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:12:42 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/12/15 18:35:00 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	test_width_flags(void)
{
	int	ret1;
	int	ret2;

	printf("\n=== BONUS TEST 1: Width ===\n");
	ret1 = printf("   printf: [%10d]\n", 42);
	ret2 = ft_printf("ft_printf: [%10d]\n", 42);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");
	printf("=== BONUS TEST 2: Left justify ===\n");
	ret1 = printf("   printf: [%-10d]\n", 42);
	ret2 = ft_printf("ft_printf: [%-10d]\n", 42);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");
	printf("=== BONUS TEST 3: Zero padding ===\n");
	ret1 = printf("   printf: [%010d]\n", 42);
	ret2 = ft_printf("ft_printf: [%010d]\n", 42);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");
}

static void	test_sign_flags(void)
{
	int	ret1;
	int	ret2;

	printf("=== BONUS TEST 4: Plus sign ===\n");
	ret1 = printf("   printf: [%+d]\n", 42);
	ret2 = ft_printf("ft_printf: [%+d]\n", 42);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");
	printf("=== BONUS TEST 5: Space ===\n");
	ret1 = printf("   printf: [% d]\n", 42);
	ret2 = ft_printf("ft_printf: [% d]\n", 42);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");
}

static void	test_precision(void)
{
	int	ret1;
	int	ret2;

	printf("=== BONUS TEST 6: Precision ===\n");
	ret1 = printf("   printf: [%.5d]\n", 42);
	ret2 = ft_printf("ft_printf: [%.5d]\n", 42);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");
	printf("=== BONUS TEST 7: Precision zero ===\n");
	ret1 = printf("   printf: [%.0d]\n", 0);
	ret2 = ft_printf("ft_printf: [%.0d]\n", 0);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");
}

static void	test_hash(void)
{
	int	ret1;
	int	ret2;

	printf("=== BONUS TEST 8: Hash hex ===\n");
	ret1 = printf("   printf: [%#x]\n", 42);
	ret2 = ft_printf("ft_printf: [%#x]\n", 42);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");
	printf("=== BONUS TEST 9: Hash with zero ===\n");
	ret1 = printf("   printf: [%#x]\n", 0);
	ret2 = ft_printf("ft_printf: [%#x]\n", 0);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");
}

static void	test_combinations(void)
{
	int	ret1;
	int	ret2;

	printf("=== BONUS TEST 10: Combinations ===\n");
	ret1 = printf("   printf: [%+010d]\n", 42);
	ret2 = ft_printf("ft_printf: [%+010d]\n", 42);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");
	printf("=== BONUS TEST 11: Left + precision ===\n");
	ret1 = printf("   printf: [%-10.5d]\n", 42);
	ret2 = ft_printf("ft_printf: [%-10.5d]\n", 42);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");
	printf("=== BONUS TEST 12: String precision ===\n");
	ret1 = printf("   printf: [%.5s]\n", "Hello World");
	ret2 = ft_printf("ft_printf: [%.5s]\n", "Hello World");
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");
}

int	main(void)
{
	test_width_flags();
	test_sign_flags();
	test_precision();
	test_hash();
	test_combinations();
	printf("=== ALL BONUS TESTS COMPLETED ===\n");
	return (0);
}