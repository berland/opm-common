/*
  Copyright 2019 Equinor.
  Copyright 2017 Statoil ASA.
  Copyright 2016 Statoil ASA.

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OUTPUT_TABLES_HPP
#define OUTPUT_TABLES_HPP

#include <vector>

#include <ert/ecl/FortIO.hpp>
#include <ert/ecl/EclKW.hpp>

#include <opm/parser/eclipse/EclipseState/Tables/PvtoTable.hpp>
#include <opm/parser/eclipse/EclipseState/Tables/PvtgTable.hpp>
#include <opm/parser/eclipse/EclipseState/Tables/FlatTable.hpp>

namespace Opm {
    class UnitSystem;
    class EclipseState;

    class Tables {
    public:
        explicit Tables( const UnitSystem& units);

        void addPVTO(const std::vector<PvtoTable>& pvtoTables);
        void addPVTG(const std::vector<PvtgTable>& pvtgTables);
        void addPVTW(const PvtwTable& pvtwTable);
        void addDensity(const DensityTable& density);

        /// Add normalised PVT function tables to INIT file's TAB vector.
        ///
        /// \param[in] es Valid \c EclipseState object with accurate RUNSPEC
        ///    information on active phases and table dimensions ("TABDIMS").
        ///
        /// \param[in] logihead Flag specifications identifying which tables
        ///    to output.
        void addPVTTables(const EclipseState& es);

        /// Add normalised saturation function tables to INIT file's TAB
        /// vector.
        ///
        /// \param[in] es Valid \c EclipseState object with accurate RUNSPEC
        ///    information on active phases and table dimensions ("TABDIMS").
        void addSatFunc(const EclipseState& es);

        /// Acquire read-only reference to internal TABDIMS vector.
        const std::vector<int>& tabdims() const;

        /// Acquire read-only reference to internal TAB vector.
        const std::vector<double>& tab() const;

    private:
        /// Convention for units of measure of the result set.
        const UnitSystem& units;

        /// Offset and size information for the tabular data.
        std::vector<int> m_tabdims;

        /// Linearised tabular data of PVT and saturation functions.
        std::vector<double> data;

        void addData(const std::size_t          offset_index,
                     const std::vector<double>& new_data);

        /// Add saturation function tables corresponding to family I (SGOF,
        /// SWOF) to the tabular data (TABDIMS and TAB vectors).
        ///
        /// \param[in] es Valid \c EclipseState object with accurate table
        ///    dimensions ("TABDIMS" keyword) and an initialised \c
        ///    TableManager sub-object.
        ///
        /// \param[in] gas Whether or not gas is active the current run.
        ///
        /// \param[in] oil Whether or not oil is active the current run.
        ///
        /// \param[in] wat Whether or not water is active the current run.
        void addSatFunc_FamilyOne(const EclipseState& es,
                                  const bool          gas,
                                  const bool          oil,
                                  const bool          wat);

        /// Add saturation function tables corresponding to family II (SGFN,
        /// SOF{2,3}, SWFN) to the tabular data (TABDIMS and TAB vectors).
        ///
        /// \param[in] es Valid \c EclipseState object with accurate table
        ///    dimensions ("TABDIMS" keyword) and an initialised \c
        ///    TableManager sub-object.
        ///
        /// \param[in] gas Whether or not gas is active the current run.
        ///
        /// \param[in] oil Whether or not oil is active the current run.
        ///
        /// \param[in] wat Whether or not water is active the current run.
        void addSatFunc_FamilyTwo(const EclipseState& es,
                                  const bool          gas,
                                  const bool          oil,
                                  const bool          wat);

        /// Add water PVT tables (keyword PVTW) to the tabular data (TABDIMS
        /// and TAB vectors).
        ///
        /// \param[in] es Valid \c EclipseState object with accurate table
        ///    dimensions ("TABDIMS" keyword) and an initialised \c
        ///    TableManager sub-object.
        void addWaterPVTTables(const EclipseState& es);
    };

    /// Emit normalised tabular information (TABDIMS and TAB vectors) to
    /// ECL-like result set file (typically INIT file).
    ///
    /// \param[in] tables Collection of normalised tables.  Its \code
    ///    tabdims() \endcode and \code tab() \endcode vectors will be
    ///    emitted to \p fortio as ECL keywords "TABDIMS" and "TAB",
    ///    respectively.
    ///
    /// \param[in,out] fortio ECL-like result set file.  Typically
    ///    corresponds to a preopened stream attached to the INIT file.
    void fwrite(const Tables& tables,
                ERT::FortIO&  fortio);
}


#endif
