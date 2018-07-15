#ifndef _ACCUM_HPP
#define _ACCUM_HPP

#include <iterator>
#include "accumtraits.hpp"
#include "sumpolicy.hpp"

template <typename T, template <typename, typename> typename Policy = SumPolicy,
          typename Traits = AccumulationTraits<T>>
auto accum(T const* begin, T const* end)
{
    using AccT = typename Traits::AccT;
    AccT total = Traits::zero();
    while (begin != end) {
        Policy<AccT, T>::accumulate(total, *begin);
        begin++;
    }
    return total;
}

template <
    typename Iter, template <typename, typename> typename Policy = SumPolicy,
    typename Traits =
        AccumulationTraits<typename std::iterator_traits<Iter>::value_type>>
auto accum(Iter const& begin, Iter const& end)
{
    using AccT = typename Traits::AccT;
    using T = typename std::iterator_traits<Iter>::value_type;
    AccT total = Traits::zero();

    for (auto tmp = begin; tmp != end; tmp++) {
        Policy<AccT, T>::accumulate(total, *tmp);
    }
    return total;
}
#endif  // _ACCUM_HPP