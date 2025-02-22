/* Copyright 2022 the SumatraPDF project authors (see AUTHORS file).
   License: Simplified BSD (see COPYING.BSD) */

struct StrQueue;

constexpr u32 kVisitDirIncudeFiles = 0x1;
constexpr u32 kVisitDirIncludeDirs = 0x2;
constexpr u32 kVisitDirRecurse = 0x4;

using VisitDirCb = std::function<bool(WIN32_FIND_DATAW* fd, const char*)>;
bool VisitDir(const char* dir, u32 flg, const VisitDirCb& cb);
bool DirTraverse(const char* dir, bool recurse, const VisitDirCb& cb);
bool VisitDirs(const char* dir, bool recurse, const VisitDirCb& cb);
bool CollectPathsFromDirectory(const char* pattern, StrVec& paths, bool dirsInsteadOfFiles = false);
bool CollectFilesFromDirectory(const char* dir, StrVec& files, const VisitDirCb& fileMatches);
void StartDirTraverseAsync(StrQueue* queue, const char* dir, bool recurse);

i64 GetFileSize(WIN32_FIND_DATAW*);
bool IsDirectory(DWORD fileAttr);
bool IsRegularFile(DWORD fileAttr);
