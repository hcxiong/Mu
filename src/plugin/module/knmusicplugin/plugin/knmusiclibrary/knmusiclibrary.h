/*
 * Copyright (C) Kreogist Dev Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#ifndef KNMUSICLIBRARY_H
#define KNMUSICLIBRARY_H

#include "knmusiclibrarybase.h"

class QThread;
class KNMusicCategoryModel;
class KNJSONDatabase;
class KNMusicLibraryModel;
class KNMusicLibraryTab;
class KNMusicLibraryImageManager;
class KNMusicLibraryCategoryTab;
class KNMusicLibrary : public KNMusicLibraryBase
{
    Q_OBJECT
public:
    explicit KNMusicLibrary(QObject *parent = 0);
    ~KNMusicLibrary();
    KNMusicTab *songTab();
    KNMusicTab *artistTab();
    KNMusicTab *albumTab();
    KNMusicTab *genreTab();
    void setHeaderPlayer(KNMusicHeaderPlayerBase *player);
    void setMainPlayer(KNMusicMainPlayerBase *player);

signals:

public slots:

private slots:
    void onActionLoadLibrary();

    void onActionShowInSongs();
    void onActionShowInArtists();
    void onActionShowInAlbums();
    void onActionShowInGenres();

private:
    inline void initialSongTab();
    inline void initialArtistTab();
    inline void initialAlbumTab();
    inline void initialGenreTab();
    enum CategoryTabs
    {
        TabArtists,
        TabAlbums,
        TabGenres,
        CategoryTabsCount
    };
    QThread *m_libraryDatabaseThread,
            *m_libraryImageThread;
    QString m_libraryPath;
    KNJSONDatabase *m_libraryDatabase;
    KNMusicLibraryModel *m_libraryModel;
    KNMusicLibraryTab *m_librarySongTab;
    KNMusicLibraryImageManager *m_libraryImageManager;
    KNMusicCategoryModel *m_categoryModel[CategoryTabsCount];
    KNMusicLibraryCategoryTab *m_libraryTabs[CategoryTabsCount];
    KNMusicHeaderPlayerBase *m_headerPlayer;
};

#endif // KNMUSICLIBRARY_H
