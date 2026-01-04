#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int ret1, ret2;

	printf("\n=== TEST 1: Basic Characters ===\n");
	ret1 = printf("   printf: [%c]\n", 'A');
	ret2 = ft_printf("ft_printf: [%c]\n", 'A');
	printf("Return values: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== TEST 2: Strings ===\n");
	ret1 = printf("   printf: [%s]\n", "Hello, 42!");
	ret2 = ft_printf("ft_printf: [%s]\n", "Hello, 42!");
	printf("Return values: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== TEST 3: NULL String ===\n");
	ret1 = printf("   printf: [%s]\n", (char *)NULL);
	ret2 = ft_printf("ft_printf: [%s]\n", (char *)NULL);
	printf("Return values: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== TEST 4: Positive Integer ===\n");
	ret1 = printf("   printf: [%d]\n", 42);
	ret2 = ft_printf("ft_printf: [%d]\n", 42);
	printf("Return values: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== TEST 5: Negative Integer ===\n");
	ret1 = printf("   printf: [%d]\n", -42);
	ret2 = ft_printf("ft_printf: [%d]\n", -42);
	printf("Return values: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== TEST 6: Zero ===\n");
	ret1 = printf("   printf: [%d]\n", 0);
	ret2 = ft_printf("ft_printf: [%d]\n", 0);
	printf("Return values: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== TEST 7: INT_MIN ===\n");
	ret1 = printf("   printf: [%d]\n", INT_MIN);
	ret2 = ft_printf("ft_printf: [%d]\n", INT_MIN);
	printf("Return values: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== TEST 8: INT_MAX ===\n");
	ret1 = printf("   printf: [%d]\n", INT_MAX);
	ret2 = ft_printf("ft_printf: [%d]\n", INT_MAX);
	printf("Return values: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== TEST 9: Unsigned ===\n");
	ret1 = printf("   printf: [%u]\n", 4294967295U);
	ret2 = ft_printf("ft_printf: [%u]\n", 4294967295U);
	printf("Return values: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== TEST 10: Hex lowercase ===\n");
	ret1 = printf("   printf: [%x]\n", 255);
	ret2 = ft_printf("ft_printf: [%x]\n", 255);
	printf("Return values: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== TEST 11: Hex uppercase ===\n");
	ret1 = printf("   printf: [%X]\n", 255);
	ret2 = ft_printf("ft_printf: [%X]\n", 255);
	printf("Return values: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== TEST 12: Pointer ===\n");
	int x = 42;
	ret1 = printf("   printf: [%p]\n", (void *)&x);
	ret2 = ft_printf("ft_printf: [%p]\n", (void *)&x);
	printf("Return values: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== TEST 13: NULL Pointer ===\n");
	ret1 = printf("   printf: [%p]\n", (void *)NULL);
	ret2 = ft_printf("ft_printf: [%p]\n", (void *)NULL);
	printf("Return values: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== TEST 14: Percent ===\n");
	ret1 = printf("   printf: [%%]\n");
	ret2 = ft_printf("ft_printf: [%%]\n");
	printf("Return values: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== TEST 15: Mixed ===\n");
	ret1 = printf("   printf: [%c %s %d %u %x %X %p %%]\n", 'A', "test", -42, 42, 255, 255, (void *)&x);
	ret2 = ft_printf("ft_printf: [%c %s %d %u %x %X %p %%]\n", 'A', "test", -42, 42, 255, 255, (void *)&x);
	printf("Return values: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	return (0);
}