#include <iostream>
#include <random>

/*
IMPORTANT LESSONS
0. After working with the InvSqrt function on desmos, I have realized even further
that machine learning is really just an set equation. Howewer, emergent behavior appears
when you have a lot of equations that interact with each other. I have also realized
that the depth of the model kind of determins the number of temporary variables that
are available. It is important to not only have temporary variables, but also to
have access to previous temporary variables. resnets allow for this because for residual
connections. Bias is also important as can be seen in InvSqrt. For models that loop like a
recurrent neural network, it is possible to calculate functions like the inverse square root
given time and the proper temporary variables. In a way, this allows the model to run
like a computer. Convolutional allows the connection of local temporary variables while
matrix multiplication allows the connection of global temporary variables. Attention
is a more complex form of matrix multiplication that allows the connection of local
temporary variables to global temporary variables. there are equations out there that can
be appoximated better when you can square the input or multiply a temporary variable
with another temporary variable.
*/

float InvSqrt(float number)
{
	long i = 0x5F1FFFF9 - (*(long*)&number >> 1);
	float tmp = *(float*)&i;
	return tmp;
	return tmp * 0.703952253f * (2.38924456f - number * tmp * tmp);
}

int main()
{
	/*for (int i = 0; i < 100; i++)
	{
		float g = InvSqrt((float)i * 0.01f);
		printf("iter: %d, g: %f\n", i, g);
	}

	return 0;*/
	
	std::mt19937 engine;
	engine.seed(std::time(nullptr));
	std::uniform_int_distribution<uint32_t> distribution(0, UINT32_MAX);
	
	uint32_t arr[200] = {};
	
	for (uint32_t i = 10000; i--;)
	{
		uint32_t randomNumner = distribution(engine);
		float one = uint16_t(randomNumner >> 16) * 0.0000152590218967f;
		float two = int16_t(randomNumner & 0xffff) * 0.0000305180437934f;
		uint32_t absBits = (0x80000000 | *(uint32_t*)&two);
		float abs = *(float*)&absBits;
		//arr[uint32_t((two * abs + 1) * 100)]++;
		arr[uint32_t((two * two * two + 1) * 100)]++;
	}

	for (uint32_t i = 0; i < 200; i++)
	{
		for (uint32_t j = arr[i] * 0.1f; j--;)
		{
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}