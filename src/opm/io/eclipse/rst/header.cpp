/*
  Copyright 2020 Equinor ASA.

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <opm/io/eclipse/rst/header.hpp>
#include <opm/output/eclipse/VectorItems/intehead.hpp>
#include <opm/output/eclipse/VectorItems/logihead.hpp>
#include <opm/output/eclipse/VectorItems/doubhead.hpp>

namespace VI = ::Opm::RestartIO::Helpers::VectorItems;

namespace Opm {
namespace RestartIO {

Header::Header(const std::vector<int>& intehead, const std::vector<bool>& logihead, const std::vector<double>& doubhead) :
    nx(intehead[VI::intehead::NX]),
    ny(intehead[VI::intehead::NY]),
    nz(intehead[VI::intehead::NZ]),
    nactive(intehead[VI::intehead::NACTIV]),
    num_wells(intehead[VI::intehead::NWELLS]),
    ncwmax(intehead[VI::intehead::NCWMAX]),
    max_wells_in_group(intehead[VI::intehead::NWGMAX]),
    max_groups_in_field(intehead[VI::intehead::NGMAXZ]),
    max_wells_in_field(intehead[VI::intehead::NWMAXZ]),
    year(intehead[VI::intehead::YEAR]),
    month(intehead[VI::intehead::MONTH]),
    mday(intehead[VI::intehead::DAY]),
    hour(intehead[VI::intehead::IHOURZ]),
    minute(intehead[VI::intehead::IMINTS]),
    microsecond(intehead[VI::intehead::ISECND]),
    phase_sum(intehead[VI::intehead::PHASE]),
    niwelz(intehead[VI::intehead::NIWELZ]),
    nswelz(intehead[VI::intehead::NSWELZ]),
    nxwelz(intehead[VI::intehead::NXWELZ]),
    nzwelz(intehead[VI::intehead::NZWELZ]),
    niconz(intehead[VI::intehead::NICONZ]),
    nsconz(intehead[VI::intehead::NSCONZ]),
    nxconz(intehead[VI::intehead::NXCONZ]),
    nigrpz(intehead[VI::intehead::NIGRPZ]),
    nsgrpz(intehead[VI::intehead::NSGRPZ]),
    nxgrpz(intehead[VI::intehead::NXGRPZ]),
    nzgrpz(intehead[VI::intehead::NZGRPZ]),
    ncamax(intehead[VI::intehead::NCAMAX]),
    niaaqz(intehead[VI::intehead::NIAAQZ]),
    nsaaqz(intehead[VI::intehead::NSAAQZ]),
    nxaaqz(intehead[VI::intehead::NXAAQZ]),
    nicaqz(intehead[VI::intehead::NICAQZ]),
    nscaqz(intehead[VI::intehead::NSCAQZ]),
    nacaqz(intehead[VI::intehead::NACAQZ]),
    tstep(intehead[VI::intehead::NUM_SOLVER_STEPS]),
    report_step(intehead[VI::intehead::REPORT_STEP]),
    newtmx(intehead[VI::intehead::NEWTMX]),
    newtmn(intehead[VI::intehead::NEWTMN]),
    litmax(intehead[VI::intehead::LITMAX]),
    litmin(intehead[VI::intehead::LITMIN]),
    mxwsit(intehead[VI::intehead::MXWSIT]),
    mxwpit(intehead[VI::intehead::MXWPIT]),
    version(intehead[VI::intehead::VERSION]),
    iprog(intehead[VI::intehead::IPROG]),
    nsegwl(intehead[VI::intehead::NSEGWL]),
    nswlmx(intehead[VI::intehead::NSWLMX]),
    nsegmx(intehead[VI::intehead::NSEGMX]),
    nlbrmx(intehead[VI::intehead::NLBRMX]),
    nisegz(intehead[VI::intehead::NISEGZ]),
    nrsegz(intehead[VI::intehead::NRSEGZ]),
    nilbrz(intehead[VI::intehead::NILBRZ]),
    ntfip(intehead[VI::intehead::NTFIP]),
    nmfipr(intehead[VI::intehead::NMFIPR]),
    ngroup(intehead[VI::intehead::NGRP]),
    //
    e300_radial(logihead[VI::logihead::E300Radial]),
    e100_radial(logihead[VI::logihead::E100Radial]),
    enable_hysteris(logihead[VI::logihead::Hyster]),
    enable_msw(logihead[VI::logihead::HasMSWells]),
    is_live_oil(logihead[VI::logihead::IsLiveOil]),
    is_wet_gas(logihead[VI::logihead::IsWetGas]),
    const_comp_oil(logihead[VI::logihead::ConstCo]),
    dir_relperm(logihead[VI::logihead::DirKr]),
    reversible_relperm(logihead[VI::logihead::E100RevKr]),
    endscale(logihead[VI::logihead::EndScale]),
    dir_eps(logihead[VI::logihead::DirEPS]),
    reversible_eps(logihead[VI::logihead::RevEPS]),
    alt_eps(logihead[VI::logihead::AltEPS]),
    //
    next_timestep1(doubhead[VI::doubhead::TsInit]),
    next_timestep2(doubhead[VI::doubhead::TsMaxz]),
    max_timestep(doubhead[VI::doubhead::TsMinz]),
    guide_rate_a(doubhead[VI::doubhead::GRpar_a]),
    guide_rate_b(doubhead[VI::doubhead::GRpar_b]),
    guide_rate_c(doubhead[VI::doubhead::GRpar_c]),
    guide_rate_d(doubhead[VI::doubhead::GRpar_d]),
    guide_rate_e(doubhead[VI::doubhead::GRpar_e]),
    guide_rate_f(doubhead[VI::doubhead::GRpar_f]),
    udq_range(doubhead[VI::doubhead::UdqPar_2]),
    udq_undefined(doubhead[VI::doubhead::UdqPar_3]),
    udq_eps(doubhead[VI::doubhead::UdqPar_4])
{
}

}
}
