#pragma once
/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "Job.h"

enum EHomeShelfFlag
{
  Audio = 0x1,
  Video = 0x2,
  Totals = 0x4
};

class CHomeShelfJob : public CJob
{
public:
  CHomeShelfJob(int flag);
 ~CHomeShelfJob();

  bool UpdateVideo();
  bool UpdateMusic();
  bool UpdateTotal();
  void UpdateTvItems(CFileItemList *list);
  void UpdateMovieItems(CFileItemList *list);
  void UpdateMusicSongItems(CFileItemList *list);
  void UpdateMusicAlbumItems(CFileItemList *list);
  void UpdateMusicVideoItems(CFileItemList *list);
  const int GetFlag() const { return m_flag; };

  virtual bool DoWork();

private:
  int m_flag;
  CCriticalSection m_critsection;
  CFileItemList *m_HomeShelfTV;
  CFileItemList *m_HomeShelfMovies;
  CFileItemList *m_HomeShelfMusicAlbums;
  CFileItemList *m_HomeShelfMusicSongs;
  CFileItemList *m_HomeShelfMusicVideos;
};
