#include "card_collection.h"
#include "card_generator.h"
#include "papipp.h"
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

//	papi::event_set<PAPI_L1_TCM, PAPI_L2_TCM, PAPI_L3_TCM> events;
	CALLGRIND_START_INSTRUMENTATION;
//	events.start_counters();
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
//	events.stop_counters();
	CALLGRIND_STOP_INSTRUMENTATION;
//	std::cout << "l1 cache misse per iteration: " << events.get<PAPI_L1_TCM>().counter() / double(state.iterations()) << std::endl;
//	std::cout << "l2 cache misse per iteration: " << events.get<PAPI_L2_TCM>().counter() / double(state.iterations()) << std::endl;
//	std::cout << "l3 cache misse per iteration: " << events.get<PAPI_L3_TCM>().counter() / double(state.iterations()) << std::endl;
}
BENCHMARK(Find)->Range(64, 64<<10);

}

BENCHMARK_MAIN();

//papi::event_set<PAPI_TOT_INS, PAPI_TOT_CYC, PAPI_BR_MSP, PAPI_L1_DCM> events;

//std::cout << events.get<PAPI_TOT_INS>().counter()/double(events.get<PAPI_TOT_CYC>().counter()) << " instr per cycle\n";
//std::cout << events.get<PAPI_TOT_INS>().counter()/double(state.iterations()) << " instructions\n";
//std::cout << events.get<PAPI_L1_DCM>().counter()/double(state.iterations()) << " l1 cache misses\n"
//          << events.get<PAPI_BR_MSP>().counter()/double(state.iterations()) << " branch misses" << std::endl;
