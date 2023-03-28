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
is a more complex form of matrix multiplication that allows the connection of temporary
variables to interact with each other. there are equations out there that can
be appoximated better when you can square the input or multiply a temporary variable
with another temporary variable as can be seen in the InvSqrt function.

1. I am thinking of making a model that basically stimulates the functionality of a computer.
First computers and neural networks are vastly different. However, a neural network can
reproduce many of the functions of a computer. A computer has a ssd, ram, cpu, gpu, cache,
and a motherboard. A massive matrix multiplication can be used to move data from the any of
these components to any other component. A convolutional neural network can be used to
compute local temporary variables. Attention can be used to use temporary variables to
interact with each other and create new temporary variables. A recurrent neural network
allows for the use of temporary variables to remain persistent. There probably would be the
need for attention addition. matrix addition, multiplication, and convolutional are all
you need to create an effective and efficient model. Relu is needed for the nonlinearity
of algoritms like a for loop or if statement. The model would need to appoximate not only
functions, but algoritms as well.

2. When the model becomes more complex, it will be possible to give it the ability to use tools.
For example, it will be possible to give it the ability to use dedicated functions so
that it won't have to appoximate them. like to do bit addition, you would need a loop requiring
multiple iterations of the recurrent neural network. this can be instead be done with a dedicated
outside function. Like humans, this looping behavior is just thinking. As we build up this ability
to think, we can offload more and more of "computation" thinking to outside functions to allow
the model to focus on more complex tasks and allocation of resources. This is the same as how
humans use tools. We use tools to do the things that we are not good at. We also use tools to
speed up the things that we do a lot. We optimize what tool to make and use based on how much
time we spend doing the task and how much effort it takes to do the task. The important thing
that would allow this is a flexible output that can call out to outside functions. Chat gpt is a
good example of this. It can code its own functions, call apis, and interact with the outside world.
Although chat gpt is a very good initial step, it is both really big and slow. With a few iterations
of an optimized model like an augmented recurrent neural network with multiple kinds of activation
in the same layer, it will be possible to make a model that is much smaller and faster with possibly
better results.
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