#include "card_collection.h"
#include "card_generator.h"
#include <valgrind/callgrind.h>
#include <benchmark/benchmark.h>
#include <iostream>

namespace workshop {

void Find(benchmark::State& state)
{
	std::cout << state.max_iterations << std::endl;
	CardCollection cards;
	CardGenerator generator;
	const std::size_t max_cards_size = static_cast<std::size_t>(state.range(0));
	CALLGRIND_START_INSTRUMENTATION;
	for (auto _: state)
	{
		state.PauseTiming();
		if (cards.size() > max_cards_size)
		{
			generator = {};
			cards = {};
		}
		state.ResumeTiming();

		cards.insert(generator.get_random_card());
		benchmark::DoNotOptimize(cards);
	}
	CALLGRIND_STOP_INSTRUMENTATION;
}
BENCHMARK(Find)->Range(64, 64<<10);

}

BENCHMARK_MAIN();
