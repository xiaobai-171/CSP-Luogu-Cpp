PRIVATE
V0ID
ConsoleCmdDir(
IN HANDLE StdHandle
    )
{
BOOL IntState;
PDEVICE_OBJECT FatDevice;
PVCB pVcb;
PVOID pBuffer;
SIZE_T BufferSize;
PDIRENT pDirEntry;
CHAR FileName[13];

ULONG i,j,RootDirSectors, SpaceSize;

IntState = KeEnableInterrupts(FALSE); // 关中断
//
//得到FAT12 文件系统设备对象，然后得到卷控制块VCB
FatDevice = (PDEVICE_0BJECT)ObpLookupObjectByName(IopDeviceObjectType,"A:");
pVcb = (PVCB)FatDevice->DeviceExtension;
//
//分配一块虚拟内存做为缓冲区，然后将整个根目录区从软盘读入缓冲区。
//
pBuffer = NULL; // 不指定缓冲区的地址。由系统决定缓冲区的地址。
BufferSize = pVcb->RootDirSize; //申请的缓冲区大小与根目录区大小相同。
MmAllocateVirtualMemory(&pBuffer, &BufferSize,MEM_RESERVE | MEM_COMMIT, TRUE);

RootDirSectors = pVcb->RootDirSize / pVcb->Bpb.BytesPerSector; // 计算根目录区占用的扇区数量
for(i=0; i<RootDirSectors; i++) {
//将根目录区占用的扇区读入缓冲区
IopReadWriteSector( 
    pVcb->DiskDevice,
    pVcb->FirstRootDirSector + i,
    0,
    (PCHAR)pBuffer + pVcb->Bpb.BytesPerSector * i,
    pVcb->Bpb.BytesPerSector,
TRUE);
}
//扫描缓冲区中的根目录项，输出根目录中的文件和文件夹信息
fprintf (StdHandle, "Name | Size (Byte)| Last Write Time | Space(Byte)\n");
for(i=0; i<pVcb->Bpb.RootEntries; i++) {
    pDirEntry = (PDIRENT)(pBuffer+ 32 * i);
//
//跳过未使用的目录项和被删除的目录项
//
if(0x0 == pDirEntry->Name[0] ||
(CHAR)0xE5 == pDirEntry->Name[0])
    continue;

FatConvertDirNameToFileName(pDirEntry->Name,FileName);
//
//从文件的第一个簇开始遍历文件占用的所有簇，统计文件占用的磁盘空间
//
SpaceSize = 0;
for (j = pDirEntry->FirstCluster; j != 0 && j != 0xFF8; ) {
    j = FatGetFatEntryValue(pVcb, j);
    SpaceSize += pVcb->Bpb.BytesPerSector * pVcb->Bpb.SectorsPerCluster;
}
fprintf(StdHandle,"%s   %d  %d-%d-%d %d:%d:%d   %d\n",
FileName, pDirEntry->FileSize,1980 + pDirEntry->LastWriteDate.Year,
pDirEntry->LastWriteDate.Month, pDirEntry->LastWriteDate.Day,
pDirEntry->LastWriteTime.Hour, pDirEntry ->LastWriteTime.Minute,
pDirEntry->LastWriteTime.DoubleSeconds, SpaceSize);
//
//释放缓冲区
//
BufferSize = 0; //缓冲区大小设置为0，表示释放全部缓冲区
MmFreeVirtualMemory(&pBuffer,&BufferSize,MEM_RELEASE, TRUE);

KeEnableInterrupts(IntState);
//开中断
