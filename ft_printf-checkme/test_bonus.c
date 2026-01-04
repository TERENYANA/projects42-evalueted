#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int ret1, ret2;

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

	printf("=== BONUS TEST 4: Plus sign ===\n");
	ret1 = printf("   printf: [%+d]\n", 42);
	ret2 = ft_printf("ft_printf: [%+d]\n", 42);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== BONUS TEST 5: Space ===\n");
	ret1 = printf("   printf: [% d]\n", 42);
	ret2 = ft_printf("ft_printf: [% d]\n", 42);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== BONUS TEST 6: Precision ===\n");
	ret1 = printf("   printf: [%.5d]\n", 42);
	ret2 = ft_printf("ft_printf: [%.5d]\n", 42);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== BONUS TEST 7: Precision zero ===\n");
	ret1 = printf("   printf: [%.0d]\n", 0);
	ret2 = ft_printf("ft_printf: [%.0d]\n", 0);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== BONUS TEST 8: Hash hex ===\n");
	ret1 = printf("   printf: [%#x]\n", 42);
	ret2 = ft_printf("ft_printf: [%#x]\n", 42);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

	printf("=== BONUS TEST 9: Hash with zero ===\n");
	ret1 = printf("   printf: [%#x]\n", 0);
	ret2 = ft_printf("ft_printf: [%#x]\n", 0);
	printf("Return: %d vs %d %s\n\n", ret1, ret2, ret1 == ret2 ? "✅" : "❌");

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

	return (0);
}
